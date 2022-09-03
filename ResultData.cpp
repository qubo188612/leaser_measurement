#include "ResultData.h"

ResultData::ResultData()
{
    link_result_state=false;
    link_param_state=false;
    ptr_pcl_lineclould.reset(new pcl::PointCloud<pcl::PointXYZRGB>);
    ptr_pcl_deepclould.reset(new pcl::PointCloud<pcl::PointXYZRGB>);
    viewer.reset(new pcl::visualization::PCLVisualizer("viewer", false));
    cv_imagelinecenter=cv::Mat::zeros(CAMIMAGE_HEIGHT,CAMIMAGE_WIDTH,CV_8UC3);
    cv_deepimg=cv::Mat::zeros(CAMIMAGE_HEIGHT,CAMIMAGE_WIDTH,CV_32FC1);
}

ResultData::~ResultData()
{
    b_deepimg_working=false;
    b_deepimg_showclould_finish=false;
    b_deepimg_pushoneline=false;
}
