#include "soptopcamera.h"

Camshow::Camshow(SoptopCamera *statci_p): Node("my_eyes")
{
  _p=statci_p;

  subscription_ = this->create_subscription<sensor_msgs::msg::Image>(
        "camera_tis_node/image", rclcpp::SensorDataQoS(), std::bind(&Camshow::topic_callback, this, _1));
}

Camshow::~Camshow()
{

}

void Camshow::topic_callback(const sensor_msgs::msg::Image msg)  const
{
  if(_p->b_connect==true)
  {
    cv_bridge::CvImagePtr cv_ptr;
    cv_ptr = cv_bridge::toCvCopy(msg, "mono8");
    *(_p->cv_image)=cv_ptr->image.clone();

  //cv::imwrite("1.bmp",*cv_image);
  }
  else
  {
    rclcpp::shutdown();
  }
}

SoptopCamera::SoptopCamera()
{
  cv_image=new cv::Mat;
  b_connect=false;
  StartCamera_thread = new StartCameraThread(this);
}

SoptopCamera::~SoptopCamera()
{
  delete StartCamera_thread;
  StartCamera_thread=NULL;
  delete cv_image;
}

void SoptopCamera::InitConnect()
{
  if(b_connect==false)
  {
    b_connect=true;
    StartCamera_thread->start();
  }
}

void SoptopCamera::DisConnect()
{
  b_connect=false;
}

StartCameraThread::StartCameraThread(SoptopCamera *statci_p)
{
  _p=statci_p;
}

void StartCameraThread::run()
{
  if(_p->b_connect==true)
  {
    rclcpp::init(_p->argc,_p->argv);
    rclcpp::spin(std::make_shared<Camshow>(_p));
  }
}
