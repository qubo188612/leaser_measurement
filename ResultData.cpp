#include "ResultData.h"

ResultData::ResultData()
{
    ptr_pcl_lineclould.reset(new pcl::PointCloud<pcl::PointXYZRGB>);
    ptr_pcl_deepclould.reset(new pcl::PointCloud<pcl::PointXYZRGB>);
    viewer.reset(new pcl::visualization::PCLVisualizer("viewer", false));
}

ResultData::~ResultData()
{
    b_deepimg_working=false;
    b_deepimg_pushoneline=false;
}
