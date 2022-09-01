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

    my_alg=new algorithm(m_mcs);

    showpoint=new leaser_showpointdlg;

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
    connect(imgshow_thread, SIGNAL(Send_show_cvimage_inlab(cv::Mat)), this, SLOT(int_show_cvimage_inlab(cv::Mat)));
    connect(imgshow_thread, SIGNAL(Send_show_pclclould_list(pcl::PointCloud<pcl::PointXYZRGB>::Ptr)), this, SLOT(init_show_pclclould_list(pcl::PointCloud<pcl::PointXYZRGB>::Ptr)));

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

    connect(ui->openpointfileBtn,&QPushButton::clicked,[=](){         //连接相机

        QString fileName = QFileDialog::getOpenFileName(this, "open Image", "", "Image File(*.bmp *.pcd *.tiff *.BMP *.PCD *.TIFF)");
        QTextCodec* code = QTextCodec::codecForName("gb18030");
        std::string name = code->fromUnicode(fileName).data();
        if(name.size()>0)
        {
            showpoint->setWindowTitle("点云图像");
            showpoint->showpoint(name);
            showpoint->exec();
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
        m_mcs->e2proomdata.measurementDlg_leaser_data_mod=0;
        UpdataUi();
    });

    connect(ui->showcontourBtn,&QPushButton::clicked,[=](){      //显示轮廓
        m_mcs->e2proomdata.measurementDlg_leaser_data_mod=1;
        UpdataUi();
    });

    connect(ui->showtragetorBtn,&QPushButton::clicked,[=](){      //显示轨迹
        m_mcs->e2proomdata.measurementDlg_leaser_data_mod=2;
        UpdataUi();
        m_mcs->resultdata.viewer->removeAllPointClouds();
        m_mcs->resultdata.viewer->removeAllShapes();
    });

    connect(ui->showdeepimgBth,&QPushButton::clicked,[=](){      //显示深度图
        m_mcs->e2proomdata.measurementDlg_leaser_data_mod=3;
        UpdataUi();
    });

    connect(ui->showclouldpointBtn,&QPushButton::clicked,[=](){      //显示点云图
        m_mcs->e2proomdata.measurementDlg_leaser_data_mod=4;
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
    delete my_alg;
    delete showpoint;
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
}


void leaser_measurementDlg::img_windowshow(bool b_show,QLabel *lab_show)
{
    if(b_show==true)
    {
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
        m_mcs->cam->sop_cam[0].InitConnect(lab_show);
    }
    else
    {
        m_mcs->cam->sop_cam[0].DisConnect();
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
        ui->deepimg_label_1->setVisible(false);
        ui->deepimg_label_2->setVisible(false);
        ui->deepimg_label_3->setVisible(false);
        ui->deepimg_label_4->setVisible(false);
        ui->deepimg_StartBtn->setVisible(false);
    }
}

void leaser_measurementDlg::Cam_Mem_Updata(Int32 memHeight,Int32 memWidth)
{
    static Int32 old_memHeight=-1,old_memWidth=-1;
    static bool b_initMem=false;
    if(old_memHeight<memHeight||old_memWidth<memWidth)
    {
      old_memHeight=memHeight;
      old_memWidth=memWidth;
      if(b_initMem==false)
      {
        b_initMem=true;
      }
      else
      {
        Myhalcv2::MyhalcvMemFree();
        my_alg->Free_algMem();
      }
      Myhalcv2::MyhalcvMemInit(memHeight,memWidth);
      my_alg->Init_algMem(memHeight,memWidth);
      m_mcs->resultdata.cv_deepimg=cv::Mat::zeros(memHeight,memWidth,CV_32FC1);
    }
}

void leaser_measurementDlg::start_deepimg()
{
    float callback_timer;//定时器间隔
    m_mcs->e2proomdata.measurementDlg_deepimg_distance=ui->deepimg_Edit_1->text().toFloat();
    m_mcs->e2proomdata.measurementDlg_deepimg_speed=ui->deepimg_Edit_2->text().toFloat();
    float usetime=m_mcs->e2proomdata.measurementDlg_deepimg_distance/m_mcs->e2proomdata.measurementDlg_deepimg_speed;//获得采集时间(秒)
    float numcallback=m_mcs->e2proomdata.measurementDlg_deepimg_distance/COLS_PROPORTION;//获得采集次数
    callback_timer=usetime/numcallback;//获得采集间隔(秒/次)
    m_mcs->resultdata.deepimg_callbacknum=numcallback+0.5+DEEPIMG_CALLBACKNUM_DNUM;
    m_mcs->resultdata.deepimg_timer=callback_timer*1000.0+0.5;//(毫秒/次)
    m_mcs->resultdata.b_deepimg_working=true;
    m_mcs->resultdata.b_deepimg_showclould_finish=false;
    m_mcs->resultdata.deepimg_callbacknum_nownum=0;
    m_mcs->resultdata.f_deepimg_y=0;
    m_mcs->resultdata.ptr_pcl_deepclould->clear();
    m_mcs->resultdata.cv_deepimg=cv::Mat::zeros(m_mcs->resultdata.deepimg_callbacknum,m_mcs->resultdata.cv_deepimg.cols,CV_32FC1);
    timer_tragetor_clould->start(m_mcs->resultdata.deepimg_timer);
}

void leaser_measurementDlg::save_imgdata_cvimage(cv::Mat cv_image)
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
}

void leaser_measurementDlg::save_pcldata_pclclould(pcl::PointCloud<pcl::PointXYZRGB>::Ptr pclclould)
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
}

void leaser_measurementDlg::slot_timer_tragetor_clould()
{
    m_mcs->resultdata.deepimg_callbacknum_nownum++;
    if(m_mcs->resultdata.deepimg_callbacknum_nownum>m_mcs->resultdata.deepimg_callbacknum)
    {
        timer_tragetor_clould->stop();
        m_mcs->resultdata.b_deepimg_working=false;
        m_mcs->resultdata.b_deepimg_showclould_finish=true;
    }
    else
    {
        m_mcs->resultdata.b_deepimg_pushoneline=true;
    }
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

void leaser_measurementDlg::init_show_pclclould_list(pcl::PointCloud<pcl::PointXYZRGB>::Ptr pclclould)
{
    m_mcs->resultdata.viewer->removeAllPointClouds();
    m_mcs->resultdata.viewer->removeAllShapes();
    m_mcs->resultdata.viewer->addPointCloud(pclclould);

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

ImgWindowShowThread::ImgWindowShowThread(leaser_measurementDlg *statci_p)
{
    _p=statci_p;
}

void ImgWindowShowThread::run()
{
    while(1)
    {
        if(_p->b_imgshow_thread==true)
        {
            if(_p->m_mcs->cam->sop_cam[0].b_updataimage_finish==true)
            {
            //运行算法
               _p->pImage=_p->m_mcs->cam->sop_cam[0].cv_image->clone();
               _p->Cam_Mem_Updata(_p->pImage.rows,_p->pImage.cols);
               switch(_p->m_mcs->e2proomdata.measurementDlg_leaser_data_mod)
               {
                  case 0:   //显示原图，（不做处理）
                  {
                      if(_p->b_int_show_cvimage_inlab_finish==true)
                      {
                          _p->b_int_show_cvimage_inlab_finish=false;
                          qRegisterMetaType< cv::Mat >("cv::Mat"); //传递自定义类型信号时要添加注册
                          emit Send_show_cvimage_inlab(_p->pImage);
                      }
                      if(_p->u8_save_imgdata==1)//保存结果
                      {
                          _p->save_imgdata_cvimage(_p->pImage);
                          _p->u8_save_imgdata=0;
                      }
                  }
                  break;
                  case 1:   //显示轮廓
                  {
                      _p->my_alg->alg1_leasercenter(_p->pImage,&_p->m_mcs->resultdata.cv_imagelinecenter,&_p->m_mcs->resultdata.cv_dlinecenter,true);                      
                      if(_p->b_int_show_cvimage_inlab_finish==true)
                      {
                          _p->b_int_show_cvimage_inlab_finish=false;
                          qRegisterMetaType< cv::Mat >("cv::Mat"); //传递自定义类型信号时要添加注册
                          emit Send_show_cvimage_inlab(_p->m_mcs->resultdata.cv_imagelinecenter);
                      }
                      if(_p->u8_save_imgdata==1)//保存结果
                      {
                          _p->save_imgdata_cvimage(_p->m_mcs->resultdata.cv_imagelinecenter);
                          _p->u8_save_imgdata=0;
                      }
                  }
                  break;
                  case 2:   //显示轮廓点云
                  {
                      cv::Mat imageOut;
                      _p->my_alg->alg1_leasercenter(_p->pImage,&imageOut,&_p->m_mcs->resultdata.cv_dlinecenter,false);
                      _p->pclclass.float_to_oneline_pclclould((float*)_p->m_mcs->resultdata.cv_dlinecenter.data,_p->m_mcs->resultdata.cv_dlinecenter.cols,0,&_p->m_mcs->resultdata.ptr_pcl_lineclould);
                      if(_p->b_init_show_pclclould_list_finish==true)
                      {
                          _p->b_init_show_pclclould_list_finish=false;
                          qRegisterMetaType<pcl::PointCloud<pcl::PointXYZRGB>::Ptr>("pcl::PointCloud<pcl::PointXYZRGB>::Ptr"); //传递自定义类型信号时要添加注册
                          emit Send_show_pclclould_list(_p->m_mcs->resultdata.ptr_pcl_lineclould);
                      }
                      if(_p->u8_save_imgdata==1)//保存结果
                      {
                          _p->save_pcldata_pclclould(_p->m_mcs->resultdata.ptr_pcl_lineclould);
                          _p->u8_save_imgdata=0;
                      }
                  }
                  break;
                  case 3:   //显示深度图
                  {   
                       if(_p->m_mcs->resultdata.b_deepimg_pushoneline==true)
                       {
                           cv::Mat imageOut;
                           float *f_line=_p->m_mcs->resultdata.cv_deepimg.ptr<float>(_p->m_mcs->resultdata.deepimg_callbacknum_nownum-1);
                           _p->m_mcs->resultdata.b_deepimg_pushoneline=false;
                           _p->my_alg->alg1_leasercenter(_p->pImage,&imageOut,&_p->m_mcs->resultdata.cv_dlinecenter,false);
                           memcpy(f_line,_p->m_mcs->resultdata.cv_dlinecenter.data,sizeof(float)*_p->m_mcs->resultdata.cv_dlinecenter.cols);
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
                           _p->save_imgdata_cvimage(_p->m_mcs->resultdata.cv_deepimg);
                           _p->u8_save_imgdata=0;
                       }
                  }
                  break;
                  case 4:   //显示点云
                  {
                       if(_p->m_mcs->resultdata.b_deepimg_pushoneline==true)
                       {
                           cv::Mat imageOut;
                           _p->m_mcs->resultdata.b_deepimg_pushoneline=false;
                           _p->my_alg->alg1_leasercenter(_p->pImage,&imageOut,&_p->m_mcs->resultdata.cv_dlinecenter,false);
                           _p->m_mcs->resultdata.f_deepimg_y=(_p->m_mcs->resultdata.deepimg_callbacknum_nownum-1)*COLS_PROPORTION;
                           _p->pclclass.float_to_oneline_pclclould((float*)_p->m_mcs->resultdata.cv_dlinecenter.data,_p->m_mcs->resultdata.cv_dlinecenter.cols,_p->m_mcs->resultdata.f_deepimg_y,&_p->m_mcs->resultdata.ptr_pcl_lineclould);
                           *(_p->m_mcs->resultdata.ptr_pcl_deepclould)=*(_p->m_mcs->resultdata.ptr_pcl_deepclould)+*(_p->m_mcs->resultdata.ptr_pcl_lineclould);
                       }
                       if(_p->m_mcs->resultdata.b_deepimg_showclould_finish==true)
                       {   //采集完成,重新刷新下颜色
                           _p->m_mcs->resultdata.b_deepimg_showclould_finish=false;
                           _p->pclclass.updata_color_pclclould(&_p->m_mcs->resultdata.ptr_pcl_lineclould,&_p->m_mcs->resultdata.ptr_pcl_lineclould);
                       }
                       if(_p->b_init_show_pclclould_list_finish==true)
                       {
                           _p->b_init_show_pclclould_list_finish=false;
                           qRegisterMetaType<pcl::PointCloud<pcl::PointXYZRGB>::Ptr>("pcl::PointCloud<pcl::PointXYZRGB>::Ptr"); //传递自定义类型信号时要添加注册
                           emit Send_show_pclclould_list(_p->m_mcs->resultdata.ptr_pcl_deepclould);
                       }
                       if(_p->u8_save_imgdata==1)//保存结果
                       {
                           _p->save_pcldata_pclclould(_p->m_mcs->resultdata.ptr_pcl_deepclould);
                           _p->u8_save_imgdata=0;
                       }
                  }
                  break;
                  default:
                  break;
               }
               _p->m_mcs->cam->sop_cam[0].b_updataimage_finish=false;
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
