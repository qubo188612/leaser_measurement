#include "ResultData.h"

ResultData::ResultData()
{
    ptr_pcl_lineclould.reset(new pcl::PointCloud<pcl::PointXYZRGB>);
    viewer.reset(new pcl::visualization::PCLVisualizer("viewer", false));
}

ResultData::~ResultData()
{

}
