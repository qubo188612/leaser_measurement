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

    ui->setupUi(this);
    InitSetEdit();
    UpdataUi();

    timer_tragetor_clould=new QTimer(this);
    connect(timer_tragetor_clould,SIGNAL(timeout()),this,SLOT(slot_timer_tragetor_clould()));//slot_timer_tragetor_clould()为自定义定时器槽

    //点云显示在控件上
    ui->pclshowlib->SetRenderWindow(m_mcs->resultdata.viewer->getRenderWindow());
    m_mcs->resultdata.viewer->setupInteractor(ui->pclshowlib->GetInteractor(), ui->pclshowlib->GetRenderWindow());
    ui->pclshowlib->update();

    imgshow_thread = new ImgWindowShowThread(this);
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

        QString fileName = QFileDialog::getOpenFileName(this, "open Image", "", "Image File(*.bmp *.jpg *.jpeg *.png)");
        QTextCodec* code = QTextCodec::codecForName("gb18030");
        std::string name = code->fromUnicode(fileName).data();
        if(name.size()>0)
        {
            showpoint.setWindowTitle("点云图像");
            showpoint.show();
            showpoint.showpoint(name);
        }
    });

    connect(ui->write_cam_editBtn,&QPushButton::clicked,[=](){      //设置相机参数
        m_mcs->cam->sop_cam[0].i32_exposure=ui->exposureEdit->text().toInt();
        m_mcs->cam->sop_cam[0].updata_parameter();
        m_mcs->cam->sop_cam[0].write_para();
    });

    connect(ui->showcamimgBtn,&QPushButton::clicked,[=](){      //显示原图
        m_mcs->e2proomdata.measurementDlg_leaser_data_mod=0;
        m_mcs->cam->sop_cam[0].b_pause_show_image_inlab=false;    //显示原图
        UpdataUi();
    });

    connect(ui->showcontourBtn,&QPushButton::clicked,[=](){      //显示轮廓
        m_mcs->e2proomdata.measurementDlg_leaser_data_mod=1;
        m_mcs->cam->sop_cam[0].b_pause_show_image_inlab=true;     //显示处理图，要暂停原图显示
        UpdataUi();
    });

    connect(ui->showtragetorBtn,&QPushButton::clicked,[=](){      //显示轨迹
        m_mcs->e2proomdata.measurementDlg_leaser_data_mod=2;
        m_mcs->cam->sop_cam[0].b_pause_show_image_inlab=true;     //显示处理图，要暂停原图显示
        UpdataUi();
        m_mcs->resultdata.viewer->removeAllPointClouds();
        m_mcs->resultdata.viewer->removeAllShapes();
    });

    connect(ui->showdeepimgBth,&QPushButton::clicked,[=](){      //显示深度图
        m_mcs->e2proomdata.measurementDlg_leaser_data_mod=3;
        m_mcs->cam->sop_cam[0].b_pause_show_image_inlab=true;     //显示处理图，要暂停原图显示
        UpdataUi();
    });

    connect(ui->showclouldpointBtn,&QPushButton::clicked,[=](){      //显示点云图
        m_mcs->e2proomdata.measurementDlg_leaser_data_mod=4;
        m_mcs->cam->sop_cam[0].b_pause_show_image_inlab=true;     //显示处理图，要暂停原图显示
        UpdataUi();
    });

    connect(ui->saveshowBtn,&QPushButton::clicked,[=](){      //保存显示
        u8_save_imgdata=1;
    });
}

leaser_measurementDlg::~leaser_measurementDlg()
{
    m_mcs->cam->sop_cam[0].DisConnect();
    imgshow_thread->Stop();
    imgshow_thread->quit();
    imgshow_thread->wait();
    delete timer_tragetor_clould;
    delete my_alg;
    delete ui;
}

void leaser_measurementDlg::InitSetEdit()
{
    QString msg;
    QString data_min,data_max;
    ui->exposureEdit->setText(QString::number(m_mcs->cam->sop_cam[0].i32_exposure));
    data_min=QString::number(m_mcs->cam->sop_cam[0].i32_exposure_min);
    data_max=QString::number(m_mcs->cam->sop_cam[0].i32_exposure_max);
    msg="("+data_min+"-"+data_max+")";
    ui->label_2->setText(msg);
}


void leaser_measurementDlg::img_windowshow(bool b_show,QLabel *lab_show)
{
    if(b_show==true)
    {
        if(m_mcs->e2proomdata.measurementDlg_leaser_data_mod==0)
            m_mcs->cam->sop_cam[0].b_pause_show_image_inlab=false;    //显示原图
        else
            m_mcs->cam->sop_cam[0].b_pause_show_image_inlab=true;     //显示处理图，要暂停原图显示
        m_mcs->cam->sop_cam[0].InitConnect(lab_show);
    }
    else
    {
        m_mcs->cam->sop_cam[0].DisConnect();
    }
}

void leaser_measurementDlg::UpdataUi()
{
    if(m_mcs->cam->sop_cam[0].b_connect==false)
    {
        ui->connectcamBtn->setText("连接");
        ui->write_cam_editBtn->setEnabled(false);
    }
    else
    {
        ui->connectcamBtn->setText("断开");
        ui->write_cam_editBtn->setEnabled(true);
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
    }
}

void leaser_measurementDlg::save_imgdata_cvimage(cv::Mat cv_image)
{
    QString dir="./DATA/";
    QString time;
    TimeFunction to;
    to.get_time_ms(&time);
    QString format=".bmp";
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
    QImage img = QImage((const uchar*)cv_image.data, cv_image.cols, cv_image.rows,
    cv_image.cols * cv_image.channels(), format);
    img = img.scaled(ui->windowshowlib->width(),ui->windowshowlib->height(),Qt::IgnoreAspectRatio, Qt::SmoothTransformation);//图片自适应lab大小
    ui->windowshowlib->setPixmap(QPixmap::fromImage(img));
}

void leaser_measurementDlg::init_show_pclclould_list(pcl::PointCloud<pcl::PointXYZRGB>::Ptr pclclould)
{
    m_mcs->resultdata.viewer->removeAllPointClouds();
    m_mcs->resultdata.viewer->removeAllShapes();
    m_mcs->resultdata.viewer->addPointCloud(pclclould);
    ui->pclshowlib->update();
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
            if(_p->m_mcs->cam->sop_cam[0].cv_image->empty()==0)
            {
            //运行算法
               _p->pImage=_p->m_mcs->cam->sop_cam[0].cv_image->clone();
               _p->Cam_Mem_Updata(_p->pImage.rows,_p->pImage.cols);
               switch(_p->m_mcs->e2proomdata.measurementDlg_leaser_data_mod)
               {
                  case 0:   //显示原图，（不做处理）
                  {
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
                      qRegisterMetaType< cv::Mat >("cv::Mat"); //传递自定义类型信号时要添加注册
                      emit Send_show_cvimage_inlab(_p->m_mcs->resultdata.cv_imagelinecenter);
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
                      _p->pclclass.float_to_oneline_pclclould((float*)_p->m_mcs->resultdata.cv_dlinecenter.data,_p->m_mcs->resultdata.cv_dlinecenter.cols,&_p->m_mcs->resultdata.ptr_pcl_lineclould);
                      qRegisterMetaType<pcl::PointCloud<pcl::PointXYZRGB>::Ptr>("pcl::PointCloud<pcl::PointXYZRGB>::Ptr"); //传递自定义类型信号时要添加注册
                      emit Send_show_pclclould_list(_p->m_mcs->resultdata.ptr_pcl_lineclould);
                      if(_p->u8_save_imgdata==1)//保存结果
                      {
                          _p->save_pcldata_pclclould(_p->m_mcs->resultdata.ptr_pcl_lineclould);
                          _p->u8_save_imgdata=0;
                      }
                  }
                  break;
                  case 3:   //显示深度图
                  {

                  }
                  break;
                  case 4:   //显示点云
                  {

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
