#include "MyPlcFunction.h"

MyPlcFunction::MyPlcFunction()
{

}

MyPlcFunction::~MyPlcFunction()
{

}

void MyPlcFunction::cvpoint3f_to_oneline_pclclould(std::vector<cv::Point3f>cv_cloud,float x,pcl::PointCloud<pcl::PointXYZRGB>::Ptr *point_cloud_ptr_Out)
{
    pcl::PointXYZRGB point;
    float maxdata=FLT_MIN,mindata=FLT_MAX;
    int i;
    int havepoint=0;

    (*point_cloud_ptr_Out)->clear();
    for(i=0;i<cv_cloud.size();i++)
    {
        if(cv_cloud[i].z>CLOULD_POINT_NOTDATE)
        {
            if(maxdata<cv_cloud[i].y)
            {
                maxdata=cv_cloud[i].y;
                havepoint=1;
            }
            if(mindata>cv_cloud[i].y)
            {
                mindata=cv_cloud[i].y;
                havepoint=1;
            }
        }
    }
    if(havepoint!=0)
    {
        float every_add=(maxdata-mindata)/255;
        for(i=0;i<cv_cloud.size();i++)
        {
            if(cv_cloud[i].z>CLOULD_POINT_NOTDATE)
            {
                int str=255,stg=0,stb=0;
                uint8_t R=str-(cv_cloud[i].y-mindata)/every_add;
                uint8_t G=stg+(cv_cloud[i].y-mindata)/every_add;
                uint8_t B=stb+(cv_cloud[i].y-mindata)/every_add;
                uint32_t rgb = (static_cast<uint32_t>(R) << 16 | static_cast<uint32_t>(G) << 8 | static_cast<uint32_t>(B));
                point.rgb = *reinterpret_cast<float*>(&rgb);
                point.x=x;
                point.y=cv_cloud[i].x;
                point.z=cv_cloud[i].y;
                (*point_cloud_ptr_Out)->points.push_back (point);
            }
        }
    }
    (*point_cloud_ptr_Out)->width = (int) (*point_cloud_ptr_Out)->points.size ();
    (*point_cloud_ptr_Out)->height = 1;
}

void MyPlcFunction::float_to_oneline_pclclould(float *f_data,int f_datanum,float y,pcl::PointCloud<pcl::PointXYZRGB>::Ptr *point_cloud_ptr_Out)
{
    pcl::PointXYZRGB point;
    cv::Mat cf_fdata=cv::Mat(1,f_datanum,CV_32FC1);
    float maxdata=FLT_MIN,mindata=FLT_MAX;
    int i;
    int havepoint=0;

    (*point_cloud_ptr_Out)->clear();
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
        float every_add=(maxdata-mindata)/255;
        for(i=0;i<f_datanum;i++)
        {
            if(f_data[i]!=CLOULD_POINT_NOTDATE)
            {
                int str=255,stg=0,stb=0;
                uint8_t R=str-(f_data[i]-mindata)/every_add;
                uint8_t G=stg+(f_data[i]-mindata)/every_add;
                uint8_t B=stb+(f_data[i]-mindata)/every_add;
                uint32_t rgb = (static_cast<uint32_t>(R) << 16 | static_cast<uint32_t>(G) << 8 | static_cast<uint32_t>(B));
                point.rgb = *reinterpret_cast<float*>(&rgb);
                point.x=i*COLS_PROPORTION;
                point.y=y;
                point.z=f_data[i]*ROWS_PROPORTION;
                (*point_cloud_ptr_Out)->points.push_back (point);
            }
        }
    }
    (*point_cloud_ptr_Out)->width = (int) (*point_cloud_ptr_Out)->points.size ();
    (*point_cloud_ptr_Out)->height = 1;
}

void MyPlcFunction::updata_color_pclclould(pcl::PointCloud<pcl::PointXYZRGB>::Ptr *point_cloud_ptr_In,pcl::PointCloud<pcl::PointXYZRGB>::Ptr *point_cloud_ptr_Out)
{
    pcl::PointXYZ min;//用于存放三个轴的最小值
    pcl::PointXYZ max;//用于存放三个轴的最大值
    pcl::PointCloud<pcl::PointXYZ>::Ptr clould(new pcl::PointCloud<pcl::PointXYZ>);
    pcl::copyPointCloud(*(*point_cloud_ptr_In),*clould);//点云转换
    pcl::getMinMax3D(*clould,min,max);
    size_t i;
    float maxdata=max.z,mindata=min.z;
    float every_add=(maxdata-mindata)/255;
    pcl::PointXYZRGB point;
    copyPointCloud(*clould, *(*point_cloud_ptr_Out));

    for(i=0;i<(*point_cloud_ptr_In)->points.size();i++)
    {
        float f_data=(*point_cloud_ptr_In)->points[i].z;
        int str=255,stg=0,stb=0;
        uint8_t R=str-(f_data-mindata)/every_add;
        uint8_t G=stg+(f_data-mindata)/every_add;
        uint8_t B=stb+(f_data-mindata)/every_add;
        uint32_t rgb = (static_cast<uint32_t>(R) << 16 | static_cast<uint32_t>(G) << 8 | static_cast<uint32_t>(B));
        (*point_cloud_ptr_Out)->points[i].rgb = *reinterpret_cast<float*>(&rgb);
    }
}

void MyPlcFunction::pclclould_to_rangeImage(pcl::PointCloud<pcl::PointXYZRGB>::Ptr *point_cloud_ptr_In,pcl::RangeImage *rangeImage)
{
    // We now want to create a range image from the above point cloud, with a 1deg angular resolution
    //angular_resolution为模拟的深度传感器的角度分辨率，即深度图像中一个像素对应的角度大小
    float angularResolution = (float) (  0.1f * (M_PI/180.0f));  //   1.0 degree in radians
     //max_angle_width为模拟的深度传感器的水平最大采样角度，
    float maxAngleWidth     = (float) (360.0f * (M_PI/180.0f));  // 360.0 degree in radians
    //max_angle_height为模拟传感器的垂直方向最大采样角度  都转为弧度
    float maxAngleHeight    = (float) (180.0f * (M_PI/180.0f));  // 180.0 degree in radians
     //传感器的采集位置
    Eigen::Affine3f sensorPose = (Eigen::Affine3f)Eigen::Translation3f(0.0f, 0.0f, 0.0f);
     //深度图像遵循坐标系统
    pcl::RangeImage::CoordinateFrame coordinate_frame = pcl::RangeImage::CAMERA_FRAME;
    float noiseLevel=0.00;    //noise_level获取深度图像深度时，近邻点对查询点距离值的影响水平
    float minRange = 0.0f;     //min_range设置最小的获取距离，小于最小获取距离的位置为传感器的盲区
    int borderSize = 1;        //border_size获得深度图像的边缘的宽度

    (*rangeImage).createFromPointCloud(*(*point_cloud_ptr_In), angularResolution, maxAngleWidth, maxAngleHeight,
                                    sensorPose, coordinate_frame, noiseLevel, minRange, borderSize);
    float* ranges = (*rangeImage).getRangesArray();
    unsigned char* rgb_image = pcl::visualization::FloatImageUtils::getVisualImage(ranges, (*rangeImage).width, (*rangeImage).height);
    pcl::io::saveRgbPNGFile("ha.png", rgb_image, (*rangeImage).width, (*rangeImage).height);
}

void MyPlcFunction::cv_f32deepimg_to_show8deepimg(cv::Mat f32_deepimg,cv::Mat *f8_deepimg)
{
    int i,j;
    cv::Mat mask=cv::Mat::ones(f32_deepimg.rows,f32_deepimg.cols,CV_8UC1);
    *f8_deepimg=cv::Mat::zeros(f32_deepimg.rows,f32_deepimg.cols,CV_8UC1);

    for(j=0;j<f32_deepimg.rows;j++)
    {
        float *f_data=(float*)f32_deepimg.ptr<float>(j);
        u_int8_t *u8_mask=(u_int8_t*)mask.ptr<u_int8_t>(j);
        for(i=0;i<f32_deepimg.cols;i++)
        {
            if(f_data[i]==CLOULD_POINT_NOTDATE)
            {
                u8_mask[i]=0;
            }
        }
    }
    if(cv::countNonZero(mask)!=0)
    {
        cv::normalize(f32_deepimg,*f8_deepimg,0,255,cv::NORM_MINMAX,-1,mask);
        cv::convertScaleAbs(*f8_deepimg,*f8_deepimg,1,0);
    }
}

void MyPlcFunction::pointCloud2imgI(pcl::PointCloud<pcl::PointXYZRGB>::Ptr *point_cloud_ptr_In, cv::Mat *f8_deepimg,double resolution)
{
  float minx, miny, maxx, maxy, mini, maxi;
  minx = miny = mini = FLT_MAX;
  maxx = maxy = maxi = -FLT_MAX;

  // 获取点云的最大最小 x、y点的坐标
  for (int i = 0; i < (*point_cloud_ptr_In)->points.size(); i++)
  {
    minx = std::min(minx, (*point_cloud_ptr_In)->points[i].y);
    miny = std::min(miny, (*point_cloud_ptr_In)->points[i].x);
    maxx = std::max(maxx, (*point_cloud_ptr_In)->points[i].y);
    maxy = std::max(maxy, (*point_cloud_ptr_In)->points[i].x);
    maxi = std::max(maxi, (*point_cloud_ptr_In)->points[i].z);
  }

  double lx = maxx - minx;					//点云长度
  double ly = maxy - miny;					//点云宽度
  int rows = round(ly / resolution);			//图像高度
  int clos = round(lx / resolution);			//图像宽度

  *f8_deepimg = cv::Mat::zeros(rows, clos, CV_32FC1);

  //强度格网矩阵
  std::vector<std::vector<float>> vec_grid_intensity;

  //格网分配空间 及初始化
  vec_grid_intensity.resize(rows);
  //初始化格网
  for (int i = 0; i < rows; i++)
  {
    vec_grid_intensity[i].resize(clos);
  }

  //依次将点压入所在格网
  for (int i = 0; i < (*point_cloud_ptr_In)->points.size(); i++)
  {
    int m = (maxy - (*point_cloud_ptr_In)->points[i].x) / resolution;
    int n = ((*point_cloud_ptr_In)->points[i].y - minx) / resolution;

    if (m > 0 && m < rows && n > 0 && n < clos)
    {
        // 将格网中的点云的最大强度值作为格网的强度值
      vec_grid_intensity[m][n] = std::max((*point_cloud_ptr_In)->points[i].z, vec_grid_intensity[m][n]);
    }
  }

  for (int i = 0; i < rows; i++)
  {
    float * data = (*f8_deepimg).ptr<float>(i);
    for (int j = 0; j < clos; j++)
    {
      if (vec_grid_intensity[i][j] > 0)
      {
        data[j] = vec_grid_intensity[i][j];
        //各通道像素赋值
      }
    }
  }
}
