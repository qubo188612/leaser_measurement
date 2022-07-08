#ifndef MY_PARAMETERS_H
#define MY_PARAMETERS_H
#include <opencv2/opencv.hpp>
#include "cam_sen.h"

class my_parameters
{
public:
    static my_parameters *Get();

    Cam_Sen *cam;    //相机

protected:
    my_parameters();
    ~my_parameters();
};

#endif // MY_PARAMETERS_H
