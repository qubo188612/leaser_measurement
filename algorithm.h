#ifndef ALGORITHM_H
#define ALGORITHM_H

#include "myhalcv2.h"
#include "my_parameters.h"

class algorithm
{
public:
    algorithm(my_parameters *para);
    ~algorithm();

    void Init_algMem(Int32 nHeight,Int32 nWidth);
    void Free_algMem();

    Int8 alg1_leasercenter(cv::Mat cvimgIn,cv::Mat *cvimgOut,cv::Mat *cv_dlinecenter,bool show=false);//求激光中线

protected:
    my_parameters *m_para;

    Uint8 *cv8uc1_Imagebuff_image;
    Uint8 *cv8uc1_Imagebuff1;
    Uint8 *cv8uc1_Imagebuff2;
    Uint8 *cv8uc1_Imagebuff3;
    Uint8 *cv8uc1_Imagebuff4;
    Uint8 *cv8uc1_Imagebuff5;
    Uint8 *cv8uc1_Imagebuff6;
    Uint8 *cv8uc1_Imagebuff7;
    Uint8 *cv8uc1_Imagebuff8;
    Myhalcv2::MyConect ImageConect,ImageConectlong,ImageConectlongPX;
    Int32 *X_line;
    Uint8 *X_lineMark;
    Int32 *X_linedif32,*niheX,*niheY;
    float *f_line;
    Myhalcv2::houghlineinfo headlinehough,tilelinehough,minlinehough;
    Myhalcv2::MyConect Imageheadline;
    Myhalcv2::MyCountLine houghline,houghlinelearn;
    Myhalcv2::MyCountLine houghline0,houghline1;

    void MatToCvMat(Myhalcv2::Mat matIn,cv::Mat *matOut);
    void CvMatToMat(cv::Mat matIn,Myhalcv2::Mat *matOut,void *buffer);
};

#endif // ALGORITHM_H
