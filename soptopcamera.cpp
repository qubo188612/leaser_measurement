#include "soptopcamera.h"

Camshow::Camshow(SoptopCamera *statci_p): Node("my_eyes")
{
  _p=statci_p;

//system("ros2 param set gpio_raspberry_node laser True");  //激光打开
//system("ros2 param set /camera_tis_node power True");     //相机打开
//_p->updata_parameter();                                   //应用相机参数

  subscription_ = this->create_subscription<sensor_msgs::msg::Image>(
        "camera_tis_node/image", rclcpp::SensorDataQoS(), std::bind(&Camshow::topic_callback, this, _1));

//  subscriresult_ = this->create_subscription<tutorial_interfaces::msg::IfAlgorhmitmsg>(
//        "/laser_imagepos_node/result", rclcpp::SensorDataQoS(), std::bind(&Camshow::result_callback, this, _1));

}

Camshow::~Camshow()
{

}

void Camshow::topic_callback(const sensor_msgs::msg::Image msg)  const
{
  if(_p->b_connect==true)
  {
    cv_bridge::CvImagePtr cv_ptr;
    cv_ptr = cv_bridge::toCvCopy(msg, msg.encoding);
    *(_p->cv_image)=cv_ptr->image.clone();
    _p->b_updataimage_finish=true;
  }
  else
  {
//  system("ros2 param set gpio_raspberry_node laser False");  //激光关闭
//  system("ros2 param set /camera_tis_node power False");     //相机关闭
    rclcpp::shutdown();
    _p->stop_b_connect=true;
  }
}

/*
void Camshow::result_callback(tutorial_interfaces::msg::IfAlgorhmitmsg msg)  const
{
  if(_p->b_connect==true)
  {
    cv_bridge::CvImagePtr cv_ptr;
    cv_ptr = cv_bridge::toCvCopy(msg.imageout, msg.imageout.encoding);
    *(_p->cv_image)=cv_ptr->image.clone();
    _p->b_updataimage_finish=true;
  }
  else
  {
//  system("ros2 param set gpio_raspberry_node laser False");  //激光关闭
//  system("ros2 param set /camera_tis_node power False");     //相机关闭
    rclcpp::shutdown();
    _p->stop_b_connect=true;
  }
}
*/

Cloudshow::Cloudshow(SoptopCamera *statci_p): Node("my_cloud")
{
  _p=statci_p;

  subscricloud_ = this->create_subscription<tutorial_interfaces::msg::IfAlgorhmitcloud>(
        "line_center_reconstruction_node/cloud_task100_199", rclcpp::SensorDataQoS(), std::bind(&Cloudshow::cloud_callback, this, _1));

}

Cloudshow::~Cloudshow()
{

}

void Cloudshow::cloud_callback(const tutorial_interfaces::msg::IfAlgorhmitcloud msg)  const
{
  if(_p->b_connect==true)
  {
    if(msg.lasertrackoutcloud.size()>0)
    {
      std::vector<cv::Point3f> cv_ptr;
      cv_ptr.resize(msg.lasertrackoutcloud.size());
      for(int n=0;n<msg.lasertrackoutcloud.size();n++)
      {
        cv_ptr[n].x=msg.lasertrackoutcloud[n].x;
        cv_ptr[n].y=msg.lasertrackoutcloud[n].y;
        cv_ptr[n].z=msg.lasertrackoutcloud[n].u;
      }
      (*(_p->cv_line)).linepoint=cv_ptr;
      (*(_p->cv_line)).linehead=msg.header;
      _p->b_cv_lineEn=true;
    }
    else
    {
      _p->b_cv_lineEn=false;
    }
    _p->b_updatacloud_finish=true;
  }
  else
  {
//  system("ros2 param set gpio_raspberry_node laser False");  //激光关闭
//  system("ros2 param set /camera_tis_node power False");     //相机关闭
    rclcpp::shutdown();
    _p->stop_b_connect=true;
  }
}

SoptopCamera::SoptopCamera()
{
  i32_exposure_min=SOPTOPCAM_EXPOSURE_MIN;
  i32_exposure_max=SOPTOPCAM_EXPOSURE_MAX;
  i32_exposure_use=SOPTOPCAM_EXPOSURE_USE;

  read_para();

  cv_image=new cv::Mat;
  cv_line=new Ros2lineinfo;
  b_connect=false;
  b_updataimage_finish=false;
  b_updatacloud_finish=false;
  node_mode=0;
  b_stopthred=true;
  StartCamera_thread = new StartCameraThread(this);
}

SoptopCamera::~SoptopCamera()
{
  StartCamera_thread->quit();
  StartCamera_thread->wait();
  delete StartCamera_thread;
  StartCamera_thread=NULL;
  delete cv_image;
  delete cv_line;
}

void SoptopCamera::read_para()
{
    uint8_t *buff=new uint8_t[SOPTOPCAM_SAVEBUFF];
    if(buff==NULL)
    {
      init_para();
      return;
    }
    CFileOut fo;
    if(0 > fo.ReadFile(SOPTOPCAM_SYSPATH_MOTO,buff,SOPTOPCAM_SAVEBUFF))
    {
      init_para();
      return;
    }
    int32_t *i32_p;
    i32_p = (int32_t*)buff;
    i32_exposure = *i32_p;
    i32_p++;

    delete[] buff;
}

void SoptopCamera::write_para()
{
    check_para();
    uint8_t *buff=new uint8_t[SOPTOPCAM_SAVEBUFF];
    if(buff==NULL)
      return;

    int32_t *i32_p;

    i32_p = (int32_t*)buff;
    *i32_p = i32_exposure;
    i32_p ++;

    CFileOut fo;
    fo.WriteFile(SOPTOPCAM_SYSPATH_MOTO,buff,SOPTOPCAM_SAVEBUFF);

    if(buff!=NULL)
      delete []buff;
}

void SoptopCamera::check_para()
{
    if(i32_exposure<i32_exposure_min||i32_exposure>i32_exposure_max)
    {
      i32_exposure=i32_exposure_use;
    }
}

void SoptopCamera::init_para()
{
    i32_exposure=i32_exposure_use;
}

void SoptopCamera::InitConnect(QLabel *lab_show)
{
  if(b_connect==false)
  {
    m_lab_show=lab_show;
    b_connect=true;
    StartCamera_thread->start();
  }
}

void SoptopCamera::DisConnect()
{
  if(b_connect==true)
  {
    stop_b_connect=false;
    b_connect=false;
    while (stop_b_connect==false||b_stopthred==false)
    {
      QThread::sleep(0);
    }
  }
}

void SoptopCamera::updata_parameter()
{
  if(b_connect==true)
  {
    QString array="ros2 param set /camera_tis_node exposure_time ";
    QString data=QString::number(i32_exposure);
    array=array+data;
    system(array.toUtf8());
  }
}

void SoptopCamera::int_show_image_inlab()
{
  QImage::Format format = QImage::Format_RGB888;
  switch (cv_image->type())
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
  QImage img = QImage((const uchar*)cv_image->data, cv_image->cols, cv_image->rows,
  cv_image->cols * cv_image->channels(), format);
  img = img.scaled(m_lab_show->width(),m_lab_show->height(),Qt::IgnoreAspectRatio, Qt::SmoothTransformation);//图片自适应lab大小
  m_lab_show->setPixmap(QPixmap::fromImage(img));
}

StartCameraThread::StartCameraThread(SoptopCamera *statci_p)
{
  _p=statci_p;
}

void StartCameraThread::run()
{
  _p->b_stopthred=false;
  if(_p->b_connect==true)
  {
    if(_p->node_mode==0)
    {
      rclcpp::init(_p->argc,_p->argv);
      rclcpp::spin(std::make_shared<Camshow>(_p));
    }
    else if(_p->node_mode==1)
    {
      rclcpp::init(_p->argc,_p->argv);
      rclcpp::spin(std::make_shared<Cloudshow>(_p));
    }
  }
  _p->b_stopthred=true;
}


