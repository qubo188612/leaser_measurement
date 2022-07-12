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

Int8 algorithm::alg1_leasercenter(cv::Mat cvimgIn,cv::Mat *cvimgOut,cv::Mat *cv_dlinecenter,bool show)
{
    Int32 ImageWidth=cvimgIn.cols;
    Int32 ImageHeight=cvimgIn.rows;

    Uint8 bryvalue;
    Int32 i32_bryvalue;
    Int32 i,j,n,t;
    Myhalcv2::Mat imageIn;
    Myhalcv2::Mat imageGasu;
    Myhalcv2::Mat imageBry;
    Myhalcv2::Mat m16_filterIma;
    Myhalcv2::Mat m_brygujia;
    Myhalcv2::Mat m_filter;
    Myhalcv2::Mat m_tempmatIn;
    Int32 nWidth=ImageWidth;	//输入图像宽
    Int32 nHeight=ImageHeight;	//输入图像高
    Int32 dealstartYmin=10;
    Int32 dealstartXmin=10;
    Uint8 filterdata[25]={0,0,1,0,0,
                          0,0,1,0,0,
                          0,0,1,0,0,
                          0,0,1,0,0,
                          0,0,1,0,0};
    Myhalcv2::L_Point32 f_center={-1,-1};
    Int32 X_Linestarty=0;
    Int32 X_Lineendy=0;
    Int32 nstartj,nendj,nstarti,nendi;


    /*********************/
    //算法参数
    Int32 pingjun=15;
    Int32 gujiaerzhi=160;
    Int32 widthliantongdis=5;
    Int32 highliantongdis=5;
    Int32 jiguanglong=20;//激光长度
    Int32 jiguangkuandu=4;//激光宽度
    /*********************/
   //cv::cvtColor(cvimgIn, cvimgIn, cv::COLOR_BGR2GRAY);
    *cvimgOut=cvimgIn.clone();

    imageIn=Myhalcv2::MatCreat(ImageWidth,ImageHeight,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff_image);
    imageGasu=Myhalcv2::MatCreat(ImageWidth,ImageHeight,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff5);
    imageBry=Myhalcv2::MatCreat(ImageWidth,ImageHeight,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff4);
    m_brygujia=Myhalcv2::MatCreat(ImageWidth,ImageHeight,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff7);
    m16_filterIma=Myhalcv2::MatCreat(ImageWidth,ImageHeight,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff6);

    Myhalcv2::CvMatToMat(cvimgIn,&imageIn,cv8uc1_Imagebuff_image);

    Myhalcv2::Mygausspyramid(imageIn,&imageGasu);
    Myhalcv2::Mygausspyramid(imageGasu,&imageGasu);

    Myhalcv2::MyCutselfRoi(&imageGasu,dealstartXmin,dealstartYmin,nWidth/4-dealstartXmin*2,nHeight/4-dealstartYmin*2);
    Myhalcv2::Mybinaryval(imageGasu,&bryvalue,Myhalcv2::MHC_BARINYVAL_MEAN);
    i32_bryvalue=(Int32)bryvalue+pingjun;//求平均值二值化阈值
    Myhalcv2::Mybinary(imageGasu,&imageBry,Myhalcv2::MHC_BARINY_VALUE_IMG,255,i32_bryvalue,0);
    m_brygujia=Myhalcv2::MatCreatzero(nHeight/4,nWidth/4,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff7);
    Myhalcv2::Mynormalize_rowXY(imageGasu,&m_brygujia,5);
    Myhalcv2::MyCutselfRoi(&imageGasu,dealstartXmin,dealstartYmin,nWidth/4-dealstartXmin*2,nHeight/4-dealstartYmin*2);
    i32_bryvalue=gujiaerzhi;
    Myhalcv2::Mybinary(m_brygujia,&m_brygujia,Myhalcv2::MHC_BARINY_VALUE_IMG,255,i32_bryvalue,0);
    Myhalcv2::Myintersection(imageBry,m_brygujia,&imageBry);
    Myhalcv2::Myconnection(imageBry,&ImageConect,50,widthliantongdis,Myhalcv2::MHC_8LT,cv8uc1_Imagebuff3);//创建8联通区域ImageConect,最小面积120,两区域距离小于2认为同一区域
    Myhalcv2::Myselect_shape(&ImageConect,&ImageConectlong,Myhalcv2::MHC_CONNECT_HEIGHT,jiguanglong,ImageConect.nHeight);//在ImageConect中筛选出高度大于50的联通域

    Myhalcv2::Myregion_to_bin(&ImageConectlong,&imageBry,255);
    if(ImageConectlong.AllMarkPointCount==0)
    {
        return 1;
    }
    Myhalcv2::MyGetthinNoHough(&ImageConectlong,Myhalcv2::THIN_Y,jiguangkuandu,&imageBry);
    Myhalcv2::Mydeleteconnection(imageBry,&imageBry,50,highliantongdis,Myhalcv2::MHC_8LT);

    //以下的图像几乎都是完美图像,需要检测出结果
    //以下对高斯图做卷积
    m16_filterIma=Myhalcv2::MatCreatzero(nHeight/4,nWidth/4,Myhalcv2::CCV_16UC1,cv8uc1_Imagebuff6);
    m_filter=Myhalcv2::MatCreat(5,5,Myhalcv2::CCV_8UC1,filterdata);
    Myhalcv2::Myfilter(imageGasu,m_filter,&m16_filterIma,Myhalcv2::CCV_16UC1,0,f_center);
    memset(X_line,0,sizeof(Int32)*nWidth/4);
    memset(X_lineMark,0,nWidth/4);
    X_Linestarty=0;
    X_Lineendy=0;
    //以下取出二值图结果中每行卷积最大值
    m_brygujia=Myhalcv2::MatCreatzero(nHeight/4,nWidth/4,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff7);
    for(i=m16_filterIma.startx;i<m16_filterIma.startx+m16_filterIma.width;i++)
    {
        Uint16 max=0;
        Uint16 maxX=m16_filterIma.startx;
        Uint16 maxXn=0;
        for(j=m16_filterIma.starty;j<m16_filterIma.starty+m16_filterIma.height;j++)
        {
            if(imageBry.ptr_uchar[j*imageBry.nWidth+i]!=0)
            {
                if(max<m16_filterIma.ptr_ushort[j*m16_filterIma.nWidth+i])
                {
                    max=m16_filterIma.ptr_ushort[j*m16_filterIma.nWidth+i];
                    maxXn=1;
                    maxX=j;
                }
                else if(max==m16_filterIma.ptr_ushort[j*m16_filterIma.nWidth+i])
                {
                    maxXn++;
                    maxX=j+maxX;
                }
            }
        }
        if(maxXn!=0)
        {
            X_line[i]=(maxX<<1)/maxXn;
            if(X_Linestarty==0)
            {
                X_Linestarty=i;//骨架起点
            }
            X_Lineendy=i;//骨架终点
            m_brygujia.data[(X_line[i]>>1)*imageGasu.nWidth+i]=255;
        }
    }
    if(X_Lineendy==0)//没找到骨架
    {
        return 1;
    }
    Myhalcv2::Myconnection(m_brygujia,&ImageConect,5,1,Myhalcv2::MHC_8LT,cv8uc1_Imagebuff3);//先去掉离散点
    Myhalcv2::Myregion_to_bin(&ImageConect,&m_brygujia,255);
    Myhalcv2::Myconnection(m_brygujia,&ImageConect,15,1,Myhalcv2::MHC_8LT,cv8uc1_Imagebuff3);//求联通大于100的区域,联通距离10
    if(ImageConect.AllMarkPointCount==0)
        return 1;
    for(j=0;j<ImageConect.AllMarkPointCount;j++)
    {
        for(i=0;i<ImageConect.AllMarkPoint[j].PointArea;i++)
        {
            Int32 x=ImageConect.AllMarkPoint[j].point[i].x;
            X_lineMark[x]=1;
        }
    }
    Myhalcv2::Myfixdata(X_line,X_lineMark,nWidth/4);//修复空的线

    imageGasu=Myhalcv2::MatCreatzero(nHeight/4,nWidth/4,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff5);
    for(j=X_Linestarty;j<=X_Lineendy;j++)
    {
        imageGasu.data[(X_line[j]>>1)*imageGasu.nWidth+j]=255;
    }

    Myhalcv2::Mydilation_circle(imageGasu,&imageGasu,1,Myhalcv2::MHC_MORPH_RECT);

    //大图上拟合
    Myhalcv2::Mysmallest_rectangle(&ImageConect,&nstarti,&nendi,&nstartj,&nendj);
    nstarti=nstarti*4-10;
    nstartj=nstartj*4-10;
    nendi=nendi*4+10;
    nendj=nendj*4+10;
    if(nstarti<(Int32)imageIn.startx)
    {
        nstarti=imageIn.startx;
    }
    if(nstartj<(Int32)imageIn.starty)
    {
        nstartj=imageIn.starty;
    }
    if(nendi>(Int32)imageIn.startx+imageIn.width-1)
    {
        nendi=imageIn.startx+imageIn.width-1;
    }
    if(nendj>(Int32)imageIn.starty+imageIn.height-1)
    {
        nendj=imageIn.starty+imageIn.height-1;
    }

    Myhalcv2::MyCutRoi(imageIn,&m_tempmatIn,Myhalcv2::MHC_CUT_NOTCOPY,nstarti,nstartj,nendi-nstarti+1,nendj-nstartj+1);
    m_brygujia=Myhalcv2::MatCreatzero(nHeight,nWidth,Myhalcv2::CCV_8UC1,cv8uc1_Imagebuff7);
    Myhalcv2::Mygaussia(m_tempmatIn,&m_brygujia,Myhalcv2::GAUSS_WIN_5x5);
    Myhalcv2::Myfilter(m_brygujia,m_filter,&m16_filterIma,Myhalcv2::CCV_16UC1,0,f_center);

    m_brygujia=Myhalcv2::MatCreatClone(imageIn,cv8uc1_Imagebuff7);
    memset(X_line,0,sizeof(Int32)*nWidth);
    memset(X_lineMark,0,nWidth);
    X_Linestarty=0;
    X_Lineendy=0;

    for(i=nstarti;i<=nendi;i++)
    {
        Uint16 max=0;
        Uint16 maxX=nstarti;
        Uint16 maxXn=0;
        for(j=nstartj;j<=nendj;j++)
        {
            Int32 dj=(j>>2);
            Int32 di=(i>>2);
            if(imageGasu.data[dj*imageGasu.nWidth+di]!=0)
            {
                if(max<m16_filterIma.ptr_ushort[j*m16_filterIma.nWidth+i])
                {
                    max=m16_filterIma.ptr_ushort[j*m16_filterIma.nWidth+i];
                    maxXn=1;
                    maxX=j;
                }
                else if(max==m16_filterIma.ptr_ushort[j*m16_filterIma.nWidth+i])
                {
                    maxXn++;
                    maxX=j+maxX;
                }
            }
        }
        if(maxXn!=0)
        {
            X_line[i]=(((maxX<<1)/maxXn)>>1);
            X_lineMark[i]=1;
            if(X_Linestarty==0)
            {
                X_Linestarty=i;//骨架起点
            }
            X_Lineendy=i;//骨架终点
        }
    }
    Myhalcv2::Myfixdata(X_line,X_lineMark,nWidth);//修复空的线
    if(show==true)
    {
      memset(imageIn.data,0,imageIn.nWidth*imageIn.nHeight);
      for(j=X_Linestarty;j<=X_Lineendy;j++)
      {
          imageIn.data[X_line[j]*imageIn.nWidth+j]=255;
      }
      Myhalcv2::MatToCvMat(imageIn,cvimgOut);
    }
    Myhalcv2::MychangeI32toF32data(X_line,f_line,nWidth);
    *cv_dlinecenter=cv::Mat(1,nWidth,CV_32FC1);
    memcpy(cv_dlinecenter->data,f_line,sizeof(float)*nWidth);
    return 0;
}
