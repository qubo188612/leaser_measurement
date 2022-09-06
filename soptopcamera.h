#ifndef SOPTOPCAMERA_H
#define SOPTOPCAMERA_H


#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <sensor_msgs/msg/image.hpp>
#include "tutorial_interfaces/msg/if_algorhmitcloud.hpp"
#include "tutorial_interfaces/msg/if_algorhmitmsg.hpp"
#include "std_msgs/msg/header.hpp"
#include <cv_bridge/cv_bridge.h>
#include <opencv2/opencv.hpp>
#include <QObject>
#include <QThread>
#include <QLabel>
#include "FileOut.h"
#include <QTimerEvent>

#define SOPTOPCAM_SAVEBUFF		32
#define SOPTOPCAM_SYSPATH_MOTO	"./SAVE/SOPTOPCAM.bsd"

#define SOPTOPCAM_EXPOSURE_MAX    65535
#define SOPTOPCAM_EXPOSURE_USE    10000
#define SOPTOPCAM_EXPOSURE_MIN    20

using std::placeholders::_1;
using std::placeholders::_2;

class StartCameraThread;

class Ros2lineinfo
{
public:
    std_msgs::msg::Header linehead;
    std::vector<cv::Point3f> linepoint;
};

class SoptopCamera : public QObject
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

    int node_mode;      //0:订阅原图,1:订阅点云

    int i32_exposure;         //曝光值
    int i32_exposure_max;     //曝光最大值
    int i32_exposure_min;     //曝光最小值
    int i32_exposure_use;     //曝光默认值
    void updata_parameter();  //刷新相机参数

    cv::Mat *cv_image;    //相机图像
    QLabel *m_lab_show;   //显示控件位置

    Ros2lineinfo *cv_line;     //相机轮廓
    bool b_cv_lineEn;     //相机轮廓有效位

    void int_show_image_inlab();//刷新图像

    void write_para();     //保存相机参数
    void init_para();       //默认参赛

    volatile bool b_updataimage_finish; //获取最相机图像完成
    volatile bool b_updatacloud_finish; //获取点云图像完成

    volatile bool b_stopthred;

    volatile int callbacknumber;

    bool callback_error;        //图像卡住

protected:
    StartCameraThread *StartCamera_thread;

    virtual void timerEvent(QTimerEvent *event);
    int timerid1;

    volatile int oldcallbacknumber;

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

class Cloudshow : public rclcpp::Node
{
public:
    Cloudshow(SoptopCamera *statci_p);
    ~Cloudshow();

private:
    SoptopCamera *_p;
public:
    rclcpp::Subscription<tutorial_interfaces::msg::IfAlgorhmitcloud>::SharedPtr subscricloud_;
    void cloud_callback(const tutorial_interfaces::msg::IfAlgorhmitcloud msg)  const;
};

#endif // SOPTOPCAMERA_H
