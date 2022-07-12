#include "algorithm.h"

algorithm::algorithm(my_parameters *para)
{
    m_para=para;
}

algorithm::~algorithm()
{

}

void algorithm::Init_algMem(Int32 nHeight,Int32 nWidth)
{
    int bigsize;

    cv8uc1_Imagebuff_image=new Uint8 [Myhalcv2::getsizeof(Myhalcv2::CCV_32SC1)*nHeight*nWidth];
    cv8uc1_Imagebuff1=new Uint8 [Myhalcv2::getsizeof(Myhalcv2::CCV_8UC1)*nHeight*nWidth];
    cv8uc1_Imagebuff2=new Uint8 [Myhalcv2::getHoughsize()];
    cv8uc1_Imagebuff3=new Uint8 [Myhalcv2::getConectsize()*nHeight*nWidth];
    cv8uc1_Imagebuff4=new Uint8 [Myhalcv2::getsizeof(Myhalcv2::CCV_8UC1)*nHeight*nWidth];
    cv8uc1_Imagebuff5=new Uint8 [Myhalcv2::getsizeof(Myhalcv2::CCV_8UC1)*nHeight*nWidth];
    cv8uc1_Imagebuff6=new Uint8 [Myhalcv2::getsizeof(Myhalcv2::CCV_16UC1)*nHeight*nWidth];
    cv8uc1_Imagebuff7=new Uint8 [Myhalcv2::getsizeof(Myhalcv2::CCV_8UC1)*nHeight*nWidth];
    cv8uc1_Imagebuff8=new Uint8 [Myhalcv2::getsizeof(Myhalcv2::CCV_8UC1)*nHeight*nWidth];

    bigsize=nWidth>nHeight?nWidth:nHeight;
    X_line=new Int32[bigsize];
    X_lineMark=new Uint8[bigsize];
    X_linedif32=new Int32[bigsize];

    niheX=new Int32[bigsize];
    niheY=new Int32[bigsize];
    f_line=new float [bigsize];
}

void algorithm::Free_algMem()
{
    delete [] cv8uc1_Imagebuff_image;
    delete [] cv8uc1_Imagebuff1;
    delete [] cv8uc1_Imagebuff2;
    delete [] cv8uc1_Imagebuff3;
    delete [] cv8uc1_Imagebuff4;
    delete [] cv8uc1_Imagebuff5;
    delete [] cv8uc1_Imagebuff6;
    delete [] cv8uc1_Imagebuff7;
    delete [] cv8uc1_Imagebuff8;
    delete [] X_line;
    delete [] X_lineMark;
    delete [] X_linedif32;
    delete [] niheX;
    delete [] niheY;
    delete [] f_line;
}

void algorithm::MatToCvMat(Myhalcv2::Mat matIn,cv::Mat *matOut)
{
  int nWidth=matIn.nWidth;
  int nHeight=matIn.nHeight;
  switch(matIn._type)
  {
  case Myhalcv2::CCV_8UC1:
    *matOut=cv::Mat(nHeight,nWidth,CV_8UC1);
    memcpy(matOut->data,matIn.data,getsizeof(matIn._type)*nHeight*nWidth);
  break;
  case Myhalcv2::CCV_8SC1:
    *matOut=cv::Mat(nHeight,nWidth,CV_8SC1);
    memcpy(matOut->data,matIn.data,getsizeof(matIn._type)*nHeight*nWidth);
  break;
  case Myhalcv2::CCV_16UC1:
    *matOut=cv::Mat(nHeight,nWidth,CV_16UC1);
    memcpy(matOut->data,matIn.data,getsizeof(matIn._type)*nHeight*nWidth);
  break;
  case Myhalcv2::CCV_16SC1:
    *matOut=cv::Mat(nHeight,nWidth,CV_16SC1);
    memcpy(matOut->data,matIn.data,getsizeof(matIn._type)*nHeight*nWidth);
  break;
  case Myhalcv2::CCV_32SC1:
    *matOut=cv::Mat(nHeight,nWidth,CV_32SC1);
    memcpy(matOut->data,matIn.data,getsizeof(matIn._type)*nHeight*nWidth);
  break;
  case Myhalcv2::CCV_32FC1:
    *matOut=cv::Mat(nHeight,nWidth,CV_32FC1);
    memcpy(matOut->data,matIn.data,getsizeof(matIn._type)*nHeight*nWidth);
  break;
  case Myhalcv2::CCV_64FC1:
    *matOut=cv::Mat(nHeight,nWidth,CV_64FC1);
    memcpy(matOut->data,matIn.data,getsizeof(matIn._type)*nHeight*nWidth);
  break;
  case Myhalcv2::CCV_8UC3:
    *matOut=cv::Mat(nHeight,nWidth,CV_8UC3);
    for(int j=0;j<nHeight;j++)
    {
      cv::Vec3b *data=matOut->ptr<cv::Vec3b>(j);
      for(int i=0;i<nWidth;i++)
      {
        data[i][0]=matIn.ptr_Vec3b[j*nWidth+i].data1;
        data[i][1]=matIn.ptr_Vec3b[j*nWidth+i].data2;
        data[i][2]=matIn.ptr_Vec3b[j*nWidth+i].data3;
      }
    }
  break;
  case Myhalcv2::CCV_8SC3:
    *matOut=cv::Mat(nHeight,nWidth,CV_8SC3);
    for(int j=0;j<nHeight;j++)
    {
      cv::Vec3b *data=matOut->ptr<cv::Vec3b>(j);
      for(int i=0;i<nWidth;i++)
      {
        data[i][0]=matIn.ptr_Vec3ib[j*nWidth+i].data1;
        data[i][1]=matIn.ptr_Vec3ib[j*nWidth+i].data2;
        data[i][2]=matIn.ptr_Vec3ib[j*nWidth+i].data3;
      }
    }
  break;
  case Myhalcv2::CCV_16UC3:
    *matOut=cv::Mat(nHeight,nWidth,CV_16UC3);
    for(int j=0;j<nHeight;j++)
    {
      cv::Vec3s *data=matOut->ptr<cv::Vec3s>(j);
      for(int i=0;i<nWidth;i++)
      {
        data[i][0]=matIn.ptr_Vec3s[j*nWidth+i].data1;
        data[i][1]=matIn.ptr_Vec3s[j*nWidth+i].data2;
        data[i][2]=matIn.ptr_Vec3s[j*nWidth+i].data3;
      }
    }
  break;
  case Myhalcv2::CCV_16SC3:
    *matOut=cv::Mat(nHeight,nWidth,CV_16SC3);
    for(int j=0;j<nHeight;j++)
    {
      cv::Vec3w *data=matOut->ptr<cv::Vec3w>(j);
      for(int i=0;i<nWidth;i++)
      {
        data[i][0]=matIn.ptr_Vec3w[j*nWidth+i].data1;
        data[i][1]=matIn.ptr_Vec3w[j*nWidth+i].data2;
        data[i][2]=matIn.ptr_Vec3w[j*nWidth+i].data3;
      }
    }
  break;
  case Myhalcv2::CCV_32SC3:
    *matOut=cv::Mat(nHeight,nWidth,CV_32SC3);
    for(int j=0;j<nHeight;j++)
    {
      cv::Vec3i *data=matOut->ptr<cv::Vec3i>(j);
      for(int i=0;i<nWidth;i++)
      {
        data[i][0]=matIn.ptr_Vec3i[j*nWidth+i].data1;
        data[i][1]=matIn.ptr_Vec3i[j*nWidth+i].data2;
        data[i][2]=matIn.ptr_Vec3i[j*nWidth+i].data3;
      }
    }
  break;
  case Myhalcv2::CCV_32FC3:
    *matOut=cv::Mat(nHeight,nWidth,CV_32FC3);
    for(int j=0;j<nHeight;j++)
    {
      cv::Vec3f *data=matOut->ptr<cv::Vec3f>(j);
      for(int i=0;i<nWidth;i++)
      {
        data[i][0]=matIn.ptr_Vec3f[j*nWidth+i].data1;
        data[i][1]=matIn.ptr_Vec3f[j*nWidth+i].data2;
        data[i][2]=matIn.ptr_Vec3f[j*nWidth+i].data3;
      }
    }
  break;
  case Myhalcv2::CCV_64FC3:
    *matOut=cv::Mat(nHeight,nWidth,CV_32FC3);
    for(int j=0;j<nHeight;j++)
    {
      cv::Vec3d *data=matOut->ptr<cv::Vec3d>(j);
      for(int i=0;i<nWidth;i++)
      {
        data[i][0]=matIn.ptr_Vec3d[j*nWidth+i].data1;
        data[i][1]=matIn.ptr_Vec3d[j*nWidth+i].data2;
        data[i][2]=matIn.ptr_Vec3d[j*nWidth+i].data3;
      }
    }
  break;
  }
}

void algorithm::CvMatToMat(cv::Mat matIn,Myhalcv2::Mat *matOut,void *buffer)
{
  int nWidth=matIn.cols;
  int nHeight=matIn.rows;
  switch(matIn.type())
  {
  case CV_8UC1:
    (*matOut)=MatCreat(nHeight,nWidth,Myhalcv2::CCV_8UC1,buffer);
    memcpy(matOut->data,matIn.data,matIn.elemSize()*nHeight*nWidth);
  break;
  case CV_8SC1:
    (*matOut)=MatCreat(nHeight,nWidth,Myhalcv2::CCV_8SC1,buffer);
    memcpy(matOut->data,matIn.data,matIn.elemSize()*nHeight*nWidth);
  break;
  case CV_16UC1:
    (*matOut)=MatCreat(nHeight,nWidth,Myhalcv2::CCV_16UC1,buffer);
    memcpy(matOut->data,matIn.data,matIn.elemSize()*nHeight*nWidth);
  break;
  case CV_16SC1:
    (*matOut)=MatCreat(nHeight,nWidth,Myhalcv2::CCV_16SC1,buffer);
    memcpy(matOut->data,matIn.data,matIn.elemSize()*nHeight*nWidth);
  break;
  case CV_32SC1:
    (*matOut)=MatCreat(nHeight,nWidth,Myhalcv2::CCV_32SC1,buffer);
    memcpy(matOut->data,matIn.data,matIn.elemSize()*nHeight*nWidth);
  break;
  case CV_32FC1:
    (*matOut)=MatCreat(nHeight,nWidth,Myhalcv2::CCV_32FC1,buffer);
    memcpy(matOut->data,matIn.data,matIn.elemSize()*nHeight*nWidth);
  break;
  case CV_64FC1:
    (*matOut)=MatCreat(nHeight,nWidth,Myhalcv2::CCV_64FC1,buffer);
    memcpy(matOut->data,matIn.data,matIn.elemSize()*nHeight*nWidth);
  break;
  case CV_8UC3:
    (*matOut)=MatCreat(nHeight,nWidth,Myhalcv2::CCV_8UC3,buffer);
    for(int j=0;j<nHeight;j++)
    {
      cv::Vec3b *data=matIn.ptr<cv::Vec3b>(j);
      for(int i=0;i<nWidth;i++)
      {
        matOut->ptr_Vec3b[j*nWidth+i].data1=data[i][0];
        matOut->ptr_Vec3b[j*nWidth+i].data2=data[i][1];
        matOut->ptr_Vec3b[j*nWidth+i].data3=data[i][2];
      }
    }
  break;
  case CV_8SC3:
    (*matOut)=MatCreat(nHeight,nWidth,Myhalcv2::CCV_8SC3,buffer);
    for(int j=0;j<nHeight;j++)
    {
      cv::Vec3b *data=matIn.ptr<cv::Vec3b>(j);
      for(int i=0;i<nWidth;i++)
      {
        matOut->ptr_Vec3ib[j*nWidth+i].data1=data[i][0];
        matOut->ptr_Vec3ib[j*nWidth+i].data2=data[i][1];
        matOut->ptr_Vec3ib[j*nWidth+i].data3=data[i][2];
      }
    }
  break;
  case CV_16UC3:
    (*matOut)=MatCreat(nHeight,nWidth,Myhalcv2::CCV_16UC3,buffer);
    for(int j=0;j<nHeight;j++)
    {
      cv::Vec3s *data=matIn.ptr<cv::Vec3s>(j);
      for(int i=0;i<nWidth;i++)
      {
        matOut->ptr_Vec3s[j*nWidth+i].data1=data[i][0];
        matOut->ptr_Vec3s[j*nWidth+i].data2=data[i][1];
        matOut->ptr_Vec3s[j*nWidth+i].data3=data[i][2];
      }
    }
  break;
  case CV_16SC3:
    (*matOut)=MatCreat(nHeight,nWidth,Myhalcv2::CCV_16SC3,buffer);
    for(int j=0;j<nHeight;j++)
    {
      cv::Vec3w *data=matIn.ptr<cv::Vec3w>(j);
      for(int i=0;i<nWidth;i++)
      {
        matOut->ptr_Vec3w[j*nWidth+i].data1=data[i][0];
        matOut->ptr_Vec3w[j*nWidth+i].data2=data[i][1];
        matOut->ptr_Vec3w[j*nWidth+i].data3=data[i][2];
      }
    }
  break;
  case CV_32SC3:
    (*matOut)=MatCreat(nHeight,nWidth,Myhalcv2::CCV_32SC3,buffer);
    for(int j=0;j<nHeight;j++)
    {
      cv::Vec3i *data=matIn.ptr<cv::Vec3i>(j);
      for(int i=0;i<nWidth;i++)
      {
        matOut->ptr_Vec3i[j*nWidth+i].data1=data[i][0];
        matOut->ptr_Vec3i[j*nWidth+i].data2=data[i][1];
        matOut->ptr_Vec3i[j*nWidth+i].data3=data[i][2];
      }
    }
  break;
  case CV_32FC3:
    (*matOut)=MatCreat(nHeight,nWidth,Myhalcv2::CCV_32FC3,buffer);
    for(int j=0;j<nHeight;j++)
    {
      cv::Vec3f *data=matIn.ptr<cv::Vec3f>(j);
      for(int i=0;i<nWidth;i++)
      {
        matOut->ptr_Vec3f[j*nWidth+i].data1=data[i][0];
        matOut->ptr_Vec3f[j*nWidth+i].data2=data[i][1];
        matOut->ptr_Vec3f[j*nWidth+i].data3=data[i][2];
      }
    }
  break;
  case CV_64FC3:
    (*matOut)=MatCreat(nHeight,nWidth,Myhalcv2::CCV_64FC3,buffer);
    for(int j=0;j<nHeight;j++)
    {
      cv::Vec3d *data=matIn.ptr<cv::Vec3d>(j);
      for(int i=0;i<nWidth;i++)
      {
        matOut->ptr_Vec3d[j*nWidth+i].data1=data[i][0];
        matOut->ptr_Vec3d[j*nWidth+i].data2=data[i][1];
        matOut->ptr_Vec3d[j*nWidth+i].data3=data[i][2];
      }
    }
  break;
  }
}

Int8 algorithm::alg1_leasercenter(cv::Mat cv_pImage,cv::Mat *cv_pImageOut,bool show)
{
    *cv_pImageOut=cv_pImage.clone();
}
