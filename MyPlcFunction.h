#ifndef MYPLCFUNCTION_H
#define MYPLCFUNCTION_H

#include "global.h"
#include <iostream>
#include <pcl/common/common_headers.h>
#include <pcl/io/pcd_io.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/console/parse.h>
#include <opencv2/opencv.hpp>

class MyPlcFunction
{
public:
    MyPlcFunction();
    ~MyPlcFunction();

    void float_to_oneline_pclclould(float *f_data,int f_datanum,pcl::PointCloud<pcl::PointXYZRGB>::Ptr *point_cloud_ptr);//把f_data数组输出为一行点云
};

#endif // MYPLCFUNCTION_H
