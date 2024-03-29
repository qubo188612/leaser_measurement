#include "leaser_measurementdlg.h"
#include "ui_leaser_measurementdlg.h"


leaser_measurementDlg::leaser_measurementDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::leaser_measurementDlg)
{
    std::string dir = "./SAVE";
    if (access(dir.c_str(), 0) == -1)
    {
      mkdir("./SAVE",S_IRWXU);
    }
    std::string bmp = "./DATA";
    if (access(bmp.c_str(), 0) == -1)
    {
      mkdir("./DATA",S_IRWXU);
    }
    m_mcs=m_mcs->Get();
    pImage=cv::Mat::zeros(CAMIMAGE_HEIGHT,CAMIMAGE_WIDTH,CV_8UC1);

    showpoint=new leaser_showpointdlg;
    paramset=new leaser_paramsetingdlg(m_mcs);

    ui->setupUi(this);
    InitSetEdit();
    UpdataUi();

    timer_tragetor_clould=new QTimer(this);
    connect(timer_tragetor_clould,SIGNAL(timeout()),this,SLOT(slot_timer_tragetor_clould()));//slot_timer_tragetor_clould()为自定义定时器槽

    //点云显示在控件上
    ui->pclshowlib->SetRenderWindow(m_mcs->resultdata.viewer->getRenderWindow());
    m_mcs->resultdata.viewer->setupInteractor(ui->pclshowlib->GetInteractor(), ui->pclshowlib->GetRenderWindow());
    m_mcs->resultdata.viewer->addCoordinateSystem();  //添加坐标系
//  m_mcs->resultdata.viewer->initCameraParameters();//从用户默认方向观测点云
    ui->pclshowlib->update();

    imgshow_thread = new ImgWindowShowThread(this);
    b_int_show_cvimage_inlab_finish=true;
    b_init_show_pclclould_list_finish=true;
    b_int_show_record_finish=true;
    connect(imgshow_thread, SIGNAL(Send_show_cvimage_inlab(cv::Mat)), this, SLOT(int_show_cvimage_inlab(cv::Mat)));
    connect(imgshow_thread, SIGNAL(Send_show_pclclould_list(pcl::PointCloud<pcl::PointXYZRGB>::Ptr)), this, SLOT(init_show_pclclould_list(pcl::PointCloud<pcl::PointXYZRGB>::Ptr)));
    connect(imgshow_thread, SIGNAL(Send_show_record(QString)), this, SLOT(int_show_record(QString)));
    b_imgshow_thread=true;
    imgshow_thread->start();

    connect(ui->connectcamBtn,&QPushButton::clicked,[=](){
       if(m_mcs->cam->sop_cam[0].b_connect==false)
       {
          img_windowshow(true,ui->windowshowlib);
          UpdataUi();
       }
       else
       {
         img_windowshow(false,ui->windowshowlib);
         UpdataUi();
       }
    });

    connect(ui->openpointfileBtn,&QPushButton::clicked,[=](){         //连接相机)
        {
          if(m_mcs->resultdata.b_deepimg_pushoneline==false)
          {
            imgshow_thread->Lock();
            QString fileName = QFileDialog::getOpenFileName(this, "open Image", "", "Image File(*.bmp *.pcd *.tiff *.BMP *.PCD *.TIFF)");
            QTextCodec* code = QTextCodec::codecForName("gb18030");
            std::string name = code->fromUnicode(fileName).data();
            if(name.size()>0)
            {
                showpoint->setWindowTitle("点云图像");
                showpoint->showpoint(name);
                showpoint->exec();
            }
            imgshow_thread->unLock();
          }
          else
          {
            ui->record->append("等采集数据完成后再进行此操作");
          }
        }
    });

    connect(ui->write_cam_editBtn,&QPushButton::clicked,[=](){      //设置相机参数

        if(m_mcs->resultdata.link_param_state==true)
        {
            int alg0_99_threshold=ui->exposureEdit->text().toInt();
            if(alg0_99_threshold<20||alg0_99_threshold>65535)
            {
                ui->record->append("设置相机曝光值超出范围");
            }
            else
            {
                uint16_t tab_reg[1];
                tab_reg[0]=alg0_99_threshold;
                int rc=modbus_write_registers(m_mcs->resultdata.ctx_param,ALS103_EXPOSURE_TIME_REG_ADD,1,tab_reg);
                if(rc!=1)
                {
                    ui->record->append("设置曝光参数失败");
                }
                else
                {
                    m_mcs->cam->sop_cam[0].i32_exposure=alg0_99_threshold;
                    m_mcs->cam->sop_cam[0].write_para();
                    ui->record->append("设置曝光参数成功");
                }
            }
        }
        else
        {
            ui->record->append("请连接相机后再设置曝光值");
        }
    });

    connect(ui->showcamimgBtn,&QPushButton::clicked,[=](){      //显示原图     
        if(m_mcs->cam->sop_cam[0].b_connect==true&&m_mcs->e2proomdata.measurementDlg_leaser_data_mod!=0)
        {
          m_mcs->cam->sop_cam[0].DisConnect();
          m_mcs->cam->sop_cam[0].node_mode=0;
          m_mcs->cam->sop_cam[0].InitConnect(ui->windowshowlib);
        }
        m_mcs->e2proomdata.measurementDlg_leaser_data_mod=0;
        ui->record->append("切换为显示原图模式");
        UpdataUi();
    });

    connect(ui->showcontourBtn,&QPushButton::clicked,[=](){      //显示轮廓
        if(m_mcs->cam->sop_cam[0].b_connect==true&&m_mcs->e2proomdata.measurementDlg_leaser_data_mod==0)
        {
          m_mcs->cam->sop_cam[0].DisConnect();
          m_mcs->cam->sop_cam[0].node_mode=1;
          m_mcs->cam->sop_cam[0].InitConnect(ui->windowshowlib);
        }
        m_mcs->e2proomdata.measurementDlg_leaser_data_mod=1;
        ui->record->append("切换为显示轮廓模式");
        UpdataUi();
    });

    connect(ui->showtragetorBtn,&QPushButton::clicked,[=](){      //显示轨迹
        if(m_mcs->cam->sop_cam[0].b_connect==true&&m_mcs->e2proomdata.measurementDlg_leaser_data_mod==0)
        {
          m_mcs->cam->sop_cam[0].DisConnect();
          m_mcs->cam->sop_cam[0].node_mode=1;
          m_mcs->cam->sop_cam[0].InitConnect(ui->windowshowlib);
        }
        m_mcs->e2proomdata.measurementDlg_leaser_data_mod=2;
        ui->record->append("切换为显示轨迹模式");
        UpdataUi();
        m_mcs->resultdata.viewer->removeAllPointClouds();
        m_mcs->resultdata.viewer->removeAllShapes();
    });

    connect(ui->showdeepimgBth,&QPushButton::clicked,[=](){      //显示深度图
        if(m_mcs->cam->sop_cam[0].b_connect==true&&m_mcs->e2proomdata.measurementDlg_leaser_data_mod==0)
        {
          m_mcs->cam->sop_cam[0].DisConnect();
          m_mcs->cam->sop_cam[0].node_mode=1;
          m_mcs->cam->sop_cam[0].InitConnect(ui->windowshowlib);
        }
        m_mcs->e2proomdata.measurementDlg_leaser_data_mod=3;
        ui->record->append("切换为显示深度图模式");
        UpdataUi();
    });

    connect(ui->showclouldpointBtn,&QPushButton::clicked,[=](){      //显示点云图
        if(m_mcs->cam->sop_cam[0].b_connect==true&&m_mcs->e2proomdata.measurementDlg_leaser_data_mod==0)
        {
          m_mcs->cam->sop_cam[0].DisConnect();
          m_mcs->cam->sop_cam[0].node_mode=1;
          m_mcs->cam->sop_cam[0].InitConnect(ui->windowshowlib);
        }
        m_mcs->e2proomdata.measurementDlg_leaser_data_mod=4;
        ui->record->append("切换为显示点云图模式");
        UpdataUi();
    });

    connect(ui->saveshowBtn,&QPushButton::clicked,[=](){      //保存显示
        u8_save_imgdata=1;
    });

    connect(ui->deepimg_StartBtn,&QPushButton::clicked,[=](){   //一键采集深度
        if(m_mcs->resultdata.b_deepimg_working==false)//深度图空闲
        {   
        #if ACQUISITION_MOD==AUTO_MOD
            start_deepimg();
        #else

        #endif
            ui->record->append("正在采集数据......");
        }
        else
        {
            stop_deepimg();
            ui->record->append("手动停止采集");
        }
    });

    connect(ui->paramsetBtn,&QPushButton::clicked,[=](){
        if(m_mcs->resultdata.link_param_state==true)
        {
          paramset->setWindowTitle("参数设置");
          paramset->Initparam(m_mcs);
          paramset->exec();
        }
        else
        {
          ui->record->append("请先连接传感器再进行参数设置");
        }
    });
}

leaser_measurementDlg::~leaser_measurementDlg()
{
    m_mcs->cam->sop_cam[0].DisConnect();
    imgshow_thread->Stop();
    imgshow_thread->quit();
    imgshow_thread->wait();
    if(m_mcs->resultdata.link_result_state==true)
    {
        close_camer_modbus();
        modbus_free(m_mcs->resultdata.ctx_result);
        m_mcs->resultdata.link_result_state=false;
        ui->record->append("控制端口关闭");
    }
    if(m_mcs->resultdata.link_param_state==true)
    {
        modbus_close(m_mcs->resultdata.ctx_param);
        m_mcs->resultdata.link_param_state=false;
        ui->record->append("参数端口关闭");
    }
    delete timer_tragetor_clould;
    delete showpoint;
    delete paramset;
    delete ui;
}

void leaser_measurementDlg::InitSetEdit()
{
    QString msg;
    QString data_min,data_max;
    ui->IPadd->setText("192.168.1.2");
    ui->exposureEdit->setText(QString::number(m_mcs->cam->sop_cam[0].i32_exposure));
    data_min=QString::number(m_mcs->cam->sop_cam[0].i32_exposure_min);
    data_max=QString::number(m_mcs->cam->sop_cam[0].i32_exposure_max);
    msg="("+data_min+"-"+data_max+")";
    ui->label_2->setText(msg);  
    ui->deepimg_Edit_1->setText(QString::number(m_mcs->e2proomdata.measurementDlg_deepimg_distance));
    ui->deepimg_Edit_2->setText(QString::number(m_mcs->e2proomdata.measurementDlg_deepimg_speed));
    ui->deepimg_Edit_3->setText(QString::number(m_mcs->e2proomdata.measurementDlg_deepimg_pisdis));

    ui->record->document()->setMaximumBlockCount(500);   //调试窗最大设置行数
    switch(m_mcs->e2proomdata.measurementDlg_leaser_data_mod)
    {
      case 0:
        ui->record->append("当前在显示原图模式");
      break;
      case 1:
        ui->record->append("当前在显示轮廓模式");
      break;
      case 2:
        ui->record->append("当前在显示轨迹模式");
      break;
      case 3:
        ui->record->append("当前在显示深度模式");
      break;
      case 4:
        ui->record->append("当前在显示点云模式");
      break;
    }
}


void leaser_measurementDlg::img_windowshow(bool b_show,QLabel *lab_show)
{
    if(b_show==true)
    {
    #ifndef ONLY_TEST_CAMER
        if(m_mcs->resultdata.link_result_state==false)
        {
            QString server_ip=ui->IPadd->text();
            QString server_port2="1502";
            m_mcs->resultdata.ctx_result = modbus_new_tcp(server_ip.toUtf8(), server_port2.toInt());
            if (modbus_connect(m_mcs->resultdata.ctx_result) == -1)
            {
                ui->record->append("控制端口连接失败");
                modbus_free(m_mcs->resultdata.ctx_result);
                return;
            }
            m_mcs->resultdata.link_result_state=true;
            ui->record->append("控制端口连接成功");
            open_camer_modbus();
        }
        if(m_mcs->resultdata.link_param_state==false)
        {
            QString server_ip=ui->IPadd->text();
            QString server_port1="1500";
            m_mcs->resultdata.ctx_param = modbus_new_tcp(server_ip.toUtf8(), server_port1.toInt());
            if (modbus_connect(m_mcs->resultdata.ctx_param) == -1)
            {
                ui->record->append("参数端口连接失败");
                modbus_free(m_mcs->resultdata.ctx_param);
                return;
            }
            m_mcs->resultdata.link_param_state=true;
            ui->record->append("参数端口连接成功");
        }
        //设置task信息
        u_int16_t task=103;
        int rc=modbus_write_registers(m_mcs->resultdata.ctx_result,0x102,1,&task);
        if(rc!=1)
        {
            ui->record->append("激光器任务模式设置失败");
        }
        else
        {
            ui->record->append("激光器任务模式设置成功");
        }
        showupdata_tabWidget();
        if(m_mcs->e2proomdata.measurementDlg_leaser_data_mod==0)
        {
          m_mcs->cam->sop_cam[0].node_mode=0;
        }
        else
        {
          m_mcs->cam->sop_cam[0].node_mode=1;
        }
   #endif
        m_mcs->cam->sop_cam[0].InitConnect(lab_show);
    }
    else
    {
        m_mcs->cam->sop_cam[0].DisConnect();
    #ifndef ONLY_TEST_CAMER
        if(m_mcs->resultdata.link_result_state==true)
        {
            close_camer_modbus();
            modbus_free(m_mcs->resultdata.ctx_result);
            m_mcs->resultdata.link_result_state=false;
            ui->record->append("控制端口关闭");
        }
        if(m_mcs->resultdata.link_param_state==true)
        {
            modbus_close(m_mcs->resultdata.ctx_param);
            m_mcs->resultdata.link_param_state=false;
            ui->record->append("参数端口关闭");
        }
    #endif
    }
}

void leaser_measurementDlg::open_camer_modbus()
{
    if(m_mcs->resultdata.link_result_state==true)
    {
        uint16_t tab_reg[1];
        tab_reg[0]=0xff;
        int rc=modbus_write_registers(m_mcs->resultdata.ctx_result,0x101,1,tab_reg);
        if(rc!=1)
        {
            ui->record->append("激光器相机启动设置失败");
        }
        else
        {
            ui->record->append("激光器相机启动设置成功");
        }
    }
}

void leaser_measurementDlg::close_camer_modbus()
{
    if(m_mcs->resultdata.link_result_state==true)
    {
        uint16_t tab_reg[1];
        tab_reg[0]=0;
        int rc=modbus_write_registers(m_mcs->resultdata.ctx_result,0x101,1,tab_reg);
        if(rc!=1)
        {
            ui->record->append("激光器相机关闭设置失败");
        }
        else
        {
            ui->record->append("激光器相机关闭设置成功");
        }
    }
}

void leaser_measurementDlg::showupdata_tabWidget()
{
    if(m_mcs->resultdata.link_param_state==true)
    {
        int real_readnum=1;
        u_int16_t rcvdata[ALS103_REG_TOTALNUM];
        real_readnum=modbus_read_registers(m_mcs->resultdata.ctx_param,ALS103_EXPOSURE_TIME_REG_ADD,ALS103_REG_TOTALNUM,rcvdata);
        if(real_readnum<0)
        {
            ui->record->append("读取参数失败");
        }
        else
        {
            if(rcvdata[0]>65535)
            {
                m_mcs->cam->sop_cam[0].i32_exposure=65535;
            }
            else if(rcvdata[0]<20)
            {
                m_mcs->cam->sop_cam[0].i32_exposure=20;
            }
            else
            {
                m_mcs->cam->sop_cam[0].i32_exposure=rcvdata[0];
            }
            ui->exposureEdit->setText(QString::number(m_mcs->cam->sop_cam[0].i32_exposure));
            /*******************/
            //这里添加其他设置参数显示
            /*******************/
            ui->record->append("读取参数成功");
        }
    }
}


void leaser_measurementDlg::UpdataUi()
{
    if(m_mcs->cam->sop_cam[0].b_connect==false)
    {
        ui->connectcamBtn->setText("连接");
        ui->write_cam_editBtn->setEnabled(false);
        ui->deepimg_StartBtn->setEnabled(false);
    }
    else
    {
        ui->connectcamBtn->setText("断开");
        ui->write_cam_editBtn->setEnabled(true);
        ui->deepimg_StartBtn->setEnabled(true);
    }
    if(m_mcs->e2proomdata.measurementDlg_leaser_data_mod==2||m_mcs->e2proomdata.measurementDlg_leaser_data_mod==4)
    {
        //点云显示
        ui->windowshowlib->setVisible(false);
        ui->pclshowlib->setVisible(true);   
    }
    else
    {
        ui->windowshowlib->setVisible(true);
        ui->pclshowlib->setVisible(false);
    }
    if(m_mcs->e2proomdata.measurementDlg_leaser_data_mod==3||m_mcs->e2proomdata.measurementDlg_leaser_data_mod==4)
    {
        if(m_mcs->e2proomdata.measurementDlg_leaser_data_mod==3)
        {
          ui->deepimg_Edit_3->setVisible(true);
          ui->label_4->setVisible(true);
          ui->label_5->setVisible(true);
        }
        else if(m_mcs->e2proomdata.measurementDlg_leaser_data_mod==4)
        {
          ui->deepimg_Edit_3->setVisible(false);
          ui->label_4->setVisible(false);
          ui->label_5->setVisible(false);
        }
        ui->deepimg_Edit_1->setVisible(true);
        ui->deepimg_Edit_2->setVisible(true);
        ui->deepimg_label_1->setVisible(true);
        ui->deepimg_label_2->setVisible(true);
        ui->deepimg_label_3->setVisible(true);
        ui->deepimg_label_4->setVisible(true);
        ui->deepimg_StartBtn->setVisible(true);
    }
    else
    {
        ui->deepimg_Edit_1->setVisible(false);
        ui->deepimg_Edit_2->setVisible(false);
        ui->deepimg_Edit_3->setVisible(false);
        ui->deepimg_label_1->setVisible(false);
        ui->deepimg_label_2->setVisible(false);
        ui->deepimg_label_3->setVisible(false);
        ui->deepimg_label_4->setVisible(false);
        ui->deepimg_StartBtn->setVisible(false);
        ui->label_4->setVisible(false);
        ui->label_5->setVisible(false);
    }
}

void leaser_measurementDlg::start_deepimg()
{
    float callback_timer;//定时器间隔
    m_mcs->e2proomdata.measurementDlg_deepimg_distance=ui->deepimg_Edit_1->text().toFloat();
    m_mcs->e2proomdata.measurementDlg_deepimg_speed=ui->deepimg_Edit_2->text().toFloat();
    m_mcs->e2proomdata.measurementDlg_deepimg_pisdis=ui->deepimg_Edit_3->text().toFloat();
    float usetime=m_mcs->e2proomdata.measurementDlg_deepimg_distance/m_mcs->e2proomdata.measurementDlg_deepimg_speed;//获得采集时间(秒)
    m_mcs->e2proomdata.write_measurementDlg_para();


    callback_timer=usetime;//获得采集间隔(秒/次)
    m_mcs->resultdata.deepimg_timer=callback_timer*1000.0+0.5;
    m_mcs->resultdata.b_deepimg_working=true;
    m_mcs->resultdata.b_deepimg_showclould_finish=false;
    m_mcs->resultdata.f_deepimg_y=0;
    m_mcs->resultdata.b_firstpoint=false;
    m_mcs->resultdata.ptr_pcl_deepclould->clear();
//  m_mcs->resultdata.cv_deepimg=cv::Mat::zeros(m_mcs->resultdata.deepimg_callbacknum,m_mcs->resultdata.cv_deepimg.cols,CV_32FC1);
    timer_tragetor_clould->start(m_mcs->resultdata.deepimg_timer);
    m_mcs->resultdata.b_deepimg_pushoneline=true;

    ui->deepimg_StartBtn->setText("手动停止采集");
}

void leaser_measurementDlg::stop_deepimg()
{
    timer_tragetor_clould->stop();
    m_mcs->resultdata.b_deepimg_working=false;
    m_mcs->resultdata.b_deepimg_showclould_finish=true;
    m_mcs->resultdata.b_deepimg_pushoneline=false;
    ui->deepimg_StartBtn->setText("一键采集");
}

QString leaser_measurementDlg::save_imgdata_cvimage(cv::Mat cv_image)
{
    QString dir="./DATA/";
    QString time;
    TimeFunction to;
    to.get_time_ms(&time);
    QString format;
    switch(cv_image.type())
    {
    case CV_8UC1:
        format=".bmp";
    break;
    case CV_8UC3:
        format=".bmp";
    break;
    case CV_32FC1:
        format=".tiff";
    break;
    case CV_32FC3:
        format=".tiff";
    break;
    case CV_64FC1:
        format=".tiff";
    break;
    case CV_64FC3:
        format=".tiff";
    break;
    }
    dir=dir+time+format;
    cv::imwrite(dir.toStdString(),cv_image);
    return dir;
}

QString leaser_measurementDlg::save_pcldata_pclclould(pcl::PointCloud<pcl::PointXYZRGB>::Ptr pclclould)
{
    pcl::PointCloud<pcl::PointXYZ>::Ptr saveclould(new pcl::PointCloud<pcl::PointXYZ>);
    QString dir="./DATA/";
    QString time;
    TimeFunction to;
    to.get_time_ms(&time);
    QString format=".pcd";
    dir=dir+time+format;
    pcl::copyPointCloud(*pclclould,*saveclould);//点云转换
    pcl::io::savePCDFile(dir.toStdString(),*saveclould);
    return dir;
}

void leaser_measurementDlg::slot_timer_tragetor_clould()
{
    timer_tragetor_clould->stop();
    m_mcs->resultdata.b_deepimg_working=false;
    m_mcs->resultdata.b_deepimg_showclould_finish=true;
    m_mcs->resultdata.b_deepimg_pushoneline=false;
    ui->deepimg_StartBtn->setText("一键采集");
}


void leaser_measurementDlg::int_show_cvimage_inlab(cv::Mat cv_image)
{
    QImage::Format format = QImage::Format_RGB888;
    switch (cv_image.type())
    {
    case CV_8UC1:
      format = QImage::Format_Indexed8;
      break;
    case CV_8UC3:
      format = QImage::Format_RGB888;
      break;
    case CV_8UC4:
      format = QImage::Format_ARGB32;
      break;
    }
    QImage img = QImage((const uchar*)cv_image.data, cv_image.cols, cv_image.rows,cv_image.cols * cv_image.channels(), format);
    img = img.scaled(ui->windowshowlib->width(),ui->windowshowlib->height(),Qt::IgnoreAspectRatio, Qt::SmoothTransformation);//图片自适应lab大小
    ui->windowshowlib->setPixmap(QPixmap::fromImage(img));
    b_int_show_cvimage_inlab_finish=true;
}

void leaser_measurementDlg::int_show_record(QString msg)
{
    ui->record->append(msg);
    b_int_show_record_finish=true;
}

void leaser_measurementDlg::init_show_pclclould_list(pcl::PointCloud<pcl::PointXYZRGB>::Ptr pclclould)
{
    m_mcs->resultdata.viewer->removeAllPointClouds();
    m_mcs->resultdata.viewer->removeAllShapes();
    m_mcs->resultdata.viewer->addPointCloud(pclclould);
//  m_mcs->resultdata.viewer->setCameraPosition(0,-69.107376,213.45485,1,0,0,1,1,1);
    ui->pclshowlib->update();
    b_init_show_pclclould_list_finish=true;
}

void ImgWindowShowThread::Stop()
{
  if(_p->b_imgshow_thread==true)
  {
    _p->stop_b_imgshow_thread=false;
    _p->b_imgshow_thread=false;
    while (_p->stop_b_imgshow_thread==false)
    {
      sleep(0);
    }
  }
}

void ImgWindowShowThread::Lock()
{
  lock=true;
}

void ImgWindowShowThread::unLock()
{
  lock=false;
}

ImgWindowShowThread::ImgWindowShowThread(leaser_measurementDlg *statci_p)
{
    _p=statci_p;
    lock=false;
}

void ImgWindowShowThread::run()
{
    while(1)
    {
        if(_p->b_imgshow_thread==true)
        {
             if(lock==false)
             {
                //运行算法
                 switch(_p->m_mcs->e2proomdata.measurementDlg_leaser_data_mod)
                 {
                    case 0:   //显示原图，（不做处理）
                    {
                       if(_p->m_mcs->cam->sop_cam[0].b_updataimage_finish==true)
                       {
                          _p->pImage=_p->m_mcs->cam->sop_cam[0].cv_image->clone();
                          if(_p->b_int_show_cvimage_inlab_finish==true)
                          {
                              _p->b_int_show_cvimage_inlab_finish=false;
                              qRegisterMetaType< cv::Mat >("cv::Mat"); //传递自定义类型信号时要添加注册
                              emit Send_show_cvimage_inlab(_p->pImage);
                          }
                          _p->m_mcs->cam->sop_cam[0].b_updataimage_finish=false;
                       }
                       if(_p->u8_save_imgdata==1)//保存结果
                       {
                           QString str=_p->save_imgdata_cvimage(_p->pImage);
                           _p->u8_save_imgdata=0;
                           if(_p->b_int_show_record_finish==true)
                           {
                             _p->b_int_show_record_finish=false;
                             qRegisterMetaType< QString >("QString");
                             QString strname="数据保存在:";
                             strname=strname+str;
                             emit Send_show_record(strname);
                           }
                       }
                    }
                    break;
                    case 1:   //显示轮廓
                    {
                       if(_p->m_mcs->cam->sop_cam[0].b_updatacloud_finish==true)
                       {
                          _p->m_mcs->resultdata.cv_imagelinecenter=cv::Mat::zeros(CAMIMAGE_HEIGHT,CAMIMAGE_WIDTH,CV_8UC3);
                          if(_p->m_mcs->cam->sop_cam[0].b_cv_lineEn==true)
                          {
                             _p->cv_line=(*_p->m_mcs->cam->sop_cam[0].cv_line).linepoint;
                             for(int n=0;n<_p->cv_line.size();n++)
                             {
                                if(_p->cv_line[n].z<=_p->m_mcs->resultdata.cv_imagelinecenter.rows-1&&_p->cv_line[n].z>=0)
                                {
                                  int x=n;
                                  int y=_p->cv_line[n].z;
                                  y=_p->m_mcs->resultdata.cv_imagelinecenter.rows-1-y;
                                  _p->m_mcs->resultdata.cv_imagelinecenter.data[y*_p->m_mcs->resultdata.cv_imagelinecenter.cols*3+x*3]=255;
                                  _p->m_mcs->resultdata.cv_imagelinecenter.data[y*_p->m_mcs->resultdata.cv_imagelinecenter.cols*3+x*3+1]=0;
                                  _p->m_mcs->resultdata.cv_imagelinecenter.data[y*_p->m_mcs->resultdata.cv_imagelinecenter.cols*3+x*3+2]=0;
                                }
                             }
                          }

                          if(_p->b_int_show_cvimage_inlab_finish==true)
                          {
                              _p->b_int_show_cvimage_inlab_finish=false;
                              qRegisterMetaType< cv::Mat >("cv::Mat"); //传递自定义类型信号时要添加注册
                              emit Send_show_cvimage_inlab(_p->m_mcs->resultdata.cv_imagelinecenter);
                          }
                          _p->m_mcs->cam->sop_cam[0].b_updatacloud_finish=false;
                       }
                       if(_p->u8_save_imgdata==1)//保存结果
                       {
                           QString str=_p->save_imgdata_cvimage(_p->m_mcs->resultdata.cv_imagelinecenter);
                           _p->u8_save_imgdata=0;
                           if(_p->b_int_show_record_finish==true)
                           {
                             _p->b_int_show_record_finish=false;
                             qRegisterMetaType< QString >("QString");
                             QString strname="数据保存在:";
                             strname=strname+str;
                             emit Send_show_record(strname);
                           }
                       }
                    }
                    break;
                    case 2:   //显示轮廓点云
                    {
                       if(_p->m_mcs->cam->sop_cam[0].b_updatacloud_finish==true)
                       {
                           if(_p->m_mcs->cam->sop_cam[0].b_cv_lineEn==true)
                           {
                              _p->cv_line=(*_p->m_mcs->cam->sop_cam[0].cv_line).linepoint;
                              _p->pclclass.cvpoint3f_to_oneline_pclclould(_p->cv_line,0,&_p->m_mcs->resultdata.ptr_pcl_lineclould);
                              if(_p->b_init_show_pclclould_list_finish==true)
                              {
                                  _p->b_init_show_pclclould_list_finish=false;
                                  qRegisterMetaType<pcl::PointCloud<pcl::PointXYZRGB>::Ptr>("pcl::PointCloud<pcl::PointXYZRGB>::Ptr"); //传递自定义类型信号时要添加注册
                                  emit Send_show_pclclould_list(_p->m_mcs->resultdata.ptr_pcl_lineclould);
                              }
                           }
                           _p->m_mcs->cam->sop_cam[0].b_updatacloud_finish=false;
                       }
                       if(_p->u8_save_imgdata==1)//保存结果
                       {
                          QString str=_p->save_pcldata_pclclould(_p->m_mcs->resultdata.ptr_pcl_lineclould);
                          _p->u8_save_imgdata=0;
                          if(_p->b_int_show_record_finish==true)
                          {
                            _p->b_int_show_record_finish=false;
                            qRegisterMetaType< QString >("QString");
                            QString strname="数据保存在:";
                            strname=strname+str;
                            emit Send_show_record(strname);
                          }
                       }
                    }
                    break;
                    case 3:   //显示深度图
                    {
                       if(_p->m_mcs->cam->sop_cam[0].b_updatacloud_finish==true)
                       {
                           if(_p->m_mcs->resultdata.b_deepimg_pushoneline==true)
                           {
                               _p->cv_line=((*_p->m_mcs->cam->sop_cam[0].cv_line).linepoint);
                               if(_p->m_mcs->resultdata.b_firstpoint==false)
                               {
                                  _p->m_mcs->resultdata.b_firstpoint=true;
                                  _p->m_mcs->resultdata.f_deepimg_y=0;
                                  _p->m_mcs->resultdata.timeinfo_st=((*_p->m_mcs->cam->sop_cam[0].cv_line).linehead);
                               }
                               else
                               {
                                  int32_t sec2=((*_p->m_mcs->cam->sop_cam[0].cv_line).linehead).stamp.sec;
                                  int32_t sec1=_p->m_mcs->resultdata.timeinfo_st.stamp.sec;
                                  uint32_t nsec2=((*_p->m_mcs->cam->sop_cam[0].cv_line).linehead).stamp.nanosec;
                                  uint32_t nsec1=_p->m_mcs->resultdata.timeinfo_st.stamp.nanosec;
                                  double fsec2=(double)sec2+(double)nsec2/1000000000.0;
                                  double fsec1=(double)sec1+(double)nsec1/1000000000.0;
                                  _p->m_mcs->resultdata.f_deepimg_y=(fsec2-fsec1)*_p->m_mcs->e2proomdata.measurementDlg_deepimg_speed;
                               }
                               _p->pclclass.cvpoint3f_to_oneline_pclclould(_p->cv_line,_p->m_mcs->resultdata.f_deepimg_y,&_p->m_mcs->resultdata.ptr_pcl_lineclould);
                               *(_p->m_mcs->resultdata.ptr_pcl_deepclould)=*(_p->m_mcs->resultdata.ptr_pcl_deepclould)+*(_p->m_mcs->resultdata.ptr_pcl_lineclould);
                           }
                           _p->m_mcs->cam->sop_cam[0].b_updatacloud_finish=false;
                       }
                       if(_p->m_mcs->resultdata.b_deepimg_showclould_finish==true)
                       {   //采集完成,点云转深度图
                           _p->m_mcs->resultdata.b_deepimg_showclould_finish=false;

                           /**************************/
                           //测试
                           /*
                           pcl::PointCloud<pcl::PointXYZ>::Ptr pointCloud(new pcl::PointCloud<pcl::PointXYZ>);
                           pcl::io::loadPCDFile("/home/qubo/suanfabmp/dianyun/1.pcd", *pointCloud);
                           pcl::PointCloud<pcl::PointXYZRGB>::Ptr rgbclould(new pcl::PointCloud<pcl::PointXYZRGB>);
                           pcl::copyPointCloud(*pointCloud,*_p->m_mcs->resultdata.ptr_pcl_deepclould);//点云转换
                           */
                           /**************************/

                           _p->pclclass.pointCloud2imgI(&_p->m_mcs->resultdata.ptr_pcl_deepclould,&_p->m_mcs->resultdata.cv_deepimg,_p->m_mcs->e2proomdata.measurementDlg_deepimg_pisdis);
                           _p->pclclass.addpoint_image(&_p->m_mcs->resultdata.cv_deepimg,
                                                       (int)(_p->m_mcs->e2proomdata.paramsetingDlg_col_add_distance/_p->m_mcs->e2proomdata.measurementDlg_deepimg_pisdis+0.5),
                                                       (int)(_p->m_mcs->e2proomdata.paramsetingDlg_row_add_distance/_p->m_mcs->e2proomdata.measurementDlg_deepimg_pisdis+0.5));
                           if(_p->b_int_show_record_finish==true)
                           {
                             _p->b_int_show_record_finish=false;
                             qRegisterMetaType< QString >("QString");
                             emit Send_show_record("完成数据采集");
                           }
                       }
                       if(_p->b_int_show_cvimage_inlab_finish==true)
                       {
                           _p->b_int_show_cvimage_inlab_finish=false;
                           _p->pclclass.cv_f32deepimg_to_show8deepimg(_p->m_mcs->resultdata.cv_deepimg,&_p->m_mcs->resultdata.cv_8deepimg_temp);
                           qRegisterMetaType< cv::Mat >("cv::Mat"); //传递自定义类型信号时要添加注册
                           emit Send_show_cvimage_inlab(_p->m_mcs->resultdata.cv_8deepimg_temp);
                       }
                       if(_p->u8_save_imgdata==1)//保存结果
                       {
                           QString str=_p->save_imgdata_cvimage(_p->m_mcs->resultdata.cv_deepimg);
                           _p->u8_save_imgdata=0;
                           if(_p->b_int_show_record_finish==true)
                           {
                             _p->b_int_show_record_finish=false;
                             qRegisterMetaType< QString >("QString");
                             QString strname="数据保存在:";
                             strname=strname+str;
                             emit Send_show_record(strname);
                           }
                       }
                    }
                    break;
                    case 4:   //显示点云
                    {
                         if(_p->m_mcs->cam->sop_cam[0].b_updatacloud_finish==true)
                         {
                             if(_p->m_mcs->resultdata.b_deepimg_pushoneline==true)
                             {
                               if(_p->m_mcs->cam->sop_cam[0].b_cv_lineEn==true)
                               {
                                 _p->cv_line=((*_p->m_mcs->cam->sop_cam[0].cv_line).linepoint);
                                 if(_p->m_mcs->resultdata.b_firstpoint==false)
                                 {
                                    _p->m_mcs->resultdata.b_firstpoint=true;
                                    _p->m_mcs->resultdata.f_deepimg_y=0;
                                    _p->m_mcs->resultdata.timeinfo_st=((*_p->m_mcs->cam->sop_cam[0].cv_line).linehead);
                                 }
                                 else
                                 {
                                    int32_t sec2=((*_p->m_mcs->cam->sop_cam[0].cv_line).linehead).stamp.sec;
                                    int32_t sec1=_p->m_mcs->resultdata.timeinfo_st.stamp.sec;
                                    uint32_t nsec2=((*_p->m_mcs->cam->sop_cam[0].cv_line).linehead).stamp.nanosec;
                                    uint32_t nsec1=_p->m_mcs->resultdata.timeinfo_st.stamp.nanosec;
                                    double fsec2=(double)sec2+(double)nsec2/1000000000.0;
                                    double fsec1=(double)sec1+(double)nsec1/1000000000.0;
                                    _p->m_mcs->resultdata.f_deepimg_y=(fsec2-fsec1)*_p->m_mcs->e2proomdata.measurementDlg_deepimg_speed;
                                 }
                          //     _p->m_mcs->resultdata.f_deepimg_y=(_p->m_mcs->resultdata.deepimg_callbacknum_nownum-1)*COLS_PROPORTION;
                                 _p->pclclass.cvpoint3f_to_oneline_pclclould(_p->cv_line,_p->m_mcs->resultdata.f_deepimg_y,&_p->m_mcs->resultdata.ptr_pcl_lineclould);
                                 *(_p->m_mcs->resultdata.ptr_pcl_deepclould)=*(_p->m_mcs->resultdata.ptr_pcl_deepclould)+*(_p->m_mcs->resultdata.ptr_pcl_lineclould);
                               }
                             }
                             _p->m_mcs->cam->sop_cam[0].b_updatacloud_finish=false;
                         }
                         if(_p->m_mcs->resultdata.b_deepimg_showclould_finish==true)
                         {   //采集完成,重新刷新下颜色
                             _p->m_mcs->resultdata.b_deepimg_showclould_finish=false;
                             /**************************/
                             //测试
                             /*
                             pcl::PointCloud<pcl::PointXYZ>::Ptr pointCloud(new pcl::PointCloud<pcl::PointXYZ>);
                             pcl::io::loadPCDFile("/home/qubo/suanfabmp/dianyun/1.pcd", *pointCloud);
                             pcl::PointCloud<pcl::PointXYZRGB>::Ptr rgbclould(new pcl::PointCloud<pcl::PointXYZRGB>);
                             pcl::copyPointCloud(*pointCloud,*_p->m_mcs->resultdata.ptr_pcl_deepclould);//点云转换
                             */
                             /**************************/
                             _p->pclclass.updata_color_pclclould(&_p->m_mcs->resultdata.ptr_pcl_deepclould,&_p->m_mcs->resultdata.ptr_pcl_deepclould);
                             if(_p->b_int_show_record_finish==true)
                             {
                               _p->b_int_show_record_finish=false;
                               qRegisterMetaType< QString >("QString");
                               emit Send_show_record("完成数据采集");
                             }
                         }
                         if(_p->b_init_show_pclclould_list_finish==true)
                         {
                             _p->b_init_show_pclclould_list_finish=false;
                             qRegisterMetaType<pcl::PointCloud<pcl::PointXYZRGB>::Ptr>("pcl::PointCloud<pcl::PointXYZRGB>::Ptr"); //传递自定义类型信号时要添加注册
                             emit Send_show_pclclould_list(_p->m_mcs->resultdata.ptr_pcl_deepclould);
                         }
                         if(_p->u8_save_imgdata==1)//保存结果
                         {
                             QString str=_p->save_pcldata_pclclould(_p->m_mcs->resultdata.ptr_pcl_deepclould);
                             _p->u8_save_imgdata=0;
                             if(_p->b_int_show_record_finish==true)
                             {
                               _p->b_int_show_record_finish=false;
                               qRegisterMetaType< QString >("QString");
                               QString strname="数据保存在:";
                               strname=strname+str;
                               emit Send_show_record(strname);
                             }
                         }
                    }
                    break;
                    default:
                    break;
                 }
             }
             sleep(0);
        }
        else
        {
            _p->stop_b_imgshow_thread=true;
            break;
        }
    }
}
