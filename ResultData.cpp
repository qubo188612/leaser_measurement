#include "ResultData.h"

ResultData::ResultData()
{
    ptr_pcl_lineclould.reset(new pcl::PointCloud<pcl::PointXYZRGB>);
}

ResultData::~ResultData()
{

}
