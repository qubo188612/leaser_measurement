#ifndef CAM_SEN_H
#define CAM_SEN_H

#include "global.h"
#include "soptopcamera.h"

class my_parameters;

class Cam_Sen
{
public:
    static Cam_Sen *Get();

/****************************/
//soptop相机
    SoptopCamera sop_cam[CAMTOTALNUM];

/****************************/
//其他相机

/****************************/
protected:
    Cam_Sen();
    ~Cam_Sen();
};

#endif // CAM_SEN_H
