#ifndef SOPTOPCAMERA_H
#define SOPTOPCAMERA_H


#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <sensor_msgs/msg/image.hpp>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>
#include <QObject>
#include <QThread>
#include <QLabel>
#include "FileOut.h"

#define SOPTOPCAM_SAVEBUFF		32
#define SOPTOPCAM_SYSPATH_MOTO	"./SAVE/SOPTOPCAM.bsd"

#define SOPTOPCAM_EXPOSURE_MAX    65535
#define SOPTOPCAM_EXPOSURE_USE    10000
#define SOPTOPCAM_EXPOSURE_MIN    20

using std::placeholders::_1;
class StartCameraThread;

class SoptopCamera
{
public:
    SoptopCamera();
    ~SoptopCamera();

    int argc;
    char **argv;

    void InitConnect(QLabel *lab_show);   //连接相机
    void DisConnect();    //断开相机
    bool b_connect;       //是否连接相机
    bool stop_b_connect;  //是否成功断开相机

    int i32_exposure;         //曝光值
    int i32_exposure_max;     //曝光最大值
    int i32_exposure_min;     //曝光最小值
    int i32_exposure_use;     //曝光默认值
    void updata_parameter();  //刷新相机参数

    cv::Mat *cv_image;    //相机图像
    QLabel *m_lab_show;   //显示控件位置

    void int_show_image_inlab();//刷新图像

    void write_para();     //保存相机参数
    void init_para();       //默认参赛

    volatile bool b_updataimage_finish; //获取最相机图像完成
protected:
    StartCameraThread *StartCamera_thread;

    void read_para();      //读取相机参数
    void check_para();     //核对相机参数
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
