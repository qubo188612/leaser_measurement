#ifndef RESULTDATA_H
#define RESULTDATA_H
#include "opencv2/opencv.hpp"
#include <iostream>
#include <pcl/common/common_headers.h>
#include <pcl/io/pcd_io.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/console/parse.h>

class ResultData
{
public:
    ResultData();
    ~ResultData();

    cv::Mat cv_image;                                                //激光原图
    cv::Mat cv_imagelinecenter;                                      //轮廓检测结果图
    cv::Mat cv_dlinecenter;                                          //轮廓数据CV_32FC1形状，1行N列
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr ptr_pcl_lineclould;       //轮廓检测结果
    pcl::PointCloud<pcl::PointXYZRGB>::Ptr ptr_pcl_deepclould;       //深度检测结果

    pcl::visualization::PCLVisualizer::Ptr viewer;                   //界面显示的点云

    int deepimg_timer;                                               //采集深度图中断间隔采样时间ms
    int deepimg_callbacknum;                                         //采集深度图中进入中断的总次数
    int deepimg_callbacknum_nownum;                                  //采集深度图中进入中断的当前次数
    volatile bool b_deepimg_working;                                 //是否正在采集深度图
    volatile bool b_deepimg_pushoneline;                             //采集深度图中是否允许当前采集一行

};

#endif // RESULTDATA_H
