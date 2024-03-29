#ifndef RESULTDATA_H
#define RESULTDATA_H
#include "opencv2/opencv.hpp"
#include <iostream>
#include <pcl/common/common_headers.h>
#include <pcl/io/pcd_io.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/console/parse.h>
#include <modbus/modbus.h>
#include "global.h"
#include "std_msgs/msg/header.hpp"

class ResultData
{
public:
    ResultData();
    ~ResultData();

    cv::Mat cv_image;                                                //激光原图
    cv::Mat cv_imagelinecenter;                                      //轮廓检测结果图
    cv::Mat cv_dlinecenter;                                          //轮廓数据CV_32FC1形状，1行N列
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr ptr_pcl_lineclould;       //轮廓检测结果
    cv::Mat cv_deepimg;                                              //深度图检测结果(浮点)
    cv::Mat cv_8deepimg_temp;                                        //深度图检测结果(0-255)
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr ptr_pcl_deepclould;       //深度检测结果点云

    pcl::visualization::PCLVisualizer::Ptr viewer;                   //主界面显示的点云

    int deepimg_timer;                                               //采集深度图间隔采样时间ms
    volatile bool b_deepimg_working;                                 //是否正在采集深度图
    volatile bool b_deepimg_showclould_finish;                       //采集深度图是否可以显示
    float f_deepimg_y;                                               //采集深度图点云时y轴当前坐标
    bool b_firstpoint;                                               //第一个点
    bool b_deepimg_pushoneline;                                      //开始采集点云
    std_msgs::msg::Header timeinfo_st;                               //点云时间起点信息

    modbus_t *ctx_result;                                            //控制参数表
    modbus_t *ctx_param;                                             //激光头参数表
    uint8_t link_result_state;                                       //结果表获取状态
    uint8_t link_param_state;                                        //参数表获取状态
};

#endif // RESULTDATA_H
