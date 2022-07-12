#ifndef SOPTOPCAMERA_H
#define SOPTOPCAMERA_H


#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <sensor_msgs/msg/image.hpp>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>
#include <QObject>
#include <QThread>

using std::placeholders::_1;
class StartCameraThread;

class SoptopCamera
{
public:
    SoptopCamera();
    ~SoptopCamera();

    int argc;
    char **argv;

    void InitConnect();   //连接相机
    void DisConnect();    //断开相机
    bool b_connect;       //是否连接相机

    cv::Mat *cv_image;    //相机图像

protected:
    StartCameraThread *StartCamera_thread;

};

class StartCameraThread : public QThread
{

public:
    StartCameraThread(SoptopCamera *statci_p);
protected:
    void run();
private:
    SoptopCamera *_p;

};

class Camshow : public rclcpp::Node
{
public:
    Camshow(SoptopCamera *statci_p);
    ~Camshow();

private:
    SoptopCamera *_p;

public:
    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscription_;
    void topic_callback(const sensor_msgs::msg::Image msg)  const;
};

#endif // SOPTOPCAMERA_H
