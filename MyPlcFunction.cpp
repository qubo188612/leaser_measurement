#include "MyPlcFunction.h"

MyPlcFunction::MyPlcFunction()
{

}

MyPlcFunction::~MyPlcFunction()
{

}

void MyPlcFunction::float_to_oneline_pclclould(float *f_data,int f_datanum,pcl::PointCloud<pcl::PointXYZRGB>::Ptr *point_cloud_ptr)
{
    pcl::PointXYZRGB point;
    cv::Mat cf_fdata=cv::Mat(1,f_datanum,CV_32FC1);
    float maxdata=FLT_MIN,mindata=FLT_MAX;
    int i;
    int havepoint=0;

    (*point_cloud_ptr)->clear();
    for(i=0;i<f_datanum;i++)
    {
        if(f_data[i]!=CLOULD_POINT_NOTDATE)
        {
            if(maxdata<f_data[i])
            {
                maxdata=f_data[i];
                havepoint=1;
            }
            if(mindata>f_data[i])
            {
                mindata=f_data[i];
                havepoint=1;
            }
        }
    }
    if(havepoint!=0)
    {
        for(i=0;i<f_datanum;i++)
        {
            if(f_data[i]!=CLOULD_POINT_NOTDATE)
            {
                int str=255,stg=0,stb=0;
                float every_add=(maxdata-mindata)/255;
                uint8_t R=str-(f_data[i]-mindata)/every_add;
                uint8_t G=stg+(f_data[i]-mindata)/every_add;
                uint8_t B=stb+(f_data[i]-mindata)/every_add;
                uint32_t rgb = (static_cast<uint32_t>(R) << 16 | static_cast<uint32_t>(G) << 8 | static_cast<uint32_t>(B));
                point.rgb = *reinterpret_cast<float*>(&rgb);
                point.x=i*COLS_PROPORTION;
                point.y=0;
                point.z=f_data[i]*ROWS_PROPORTION;
                (*point_cloud_ptr)->points.push_back (point);
            }
        }
    }
    (*point_cloud_ptr)->width = (int) (*point_cloud_ptr)->points.size ();
    (*point_cloud_ptr)->height = 1;

//  pcl::visualization::CloudViewer viewer ("pcl—test测试");
//  viewer.showCloud(point_cloud_ptr);
//  while (!viewer.wasStopped()){ };
}
