#include "leaser_showpointdlg.h"
#include "ui_leaser_showpointdlg.h"

leaser_showpointdlg::leaser_showpointdlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::leaser_showpointdlg)
{
    ui->setupUi(this);

    pclclould.reset(new pcl::PointCloud<pcl::PointXYZ>);
}

leaser_showpointdlg::~leaser_showpointdlg()
{
    delete ui;
}

void leaser_showpointdlg::showpoint(std::string filename)
{
    QString msg=filename.c_str();
    QStringList msgList = msg.split(".");
    if(msgList[msgList.size()-1]=="BMP"||
       msgList[msgList.size()-1]=="bmp")
    {
        ui->widget->setVisible(false);
        ui->label->setVisible(true);
        cv::Mat m_srcImage = cv::imread(filename);
        if (m_srcImage.empty()==0)
        {
            cvtColor(m_srcImage, m_srcImage, cv::COLOR_BGR2RGB);//BGR转化为RGB
            QImage::Format format = QImage::Format_RGB888;
            switch (m_srcImage.type())
            {
            case CV_8UC1:
              format = QImage::Format_Indexed8;
              break;
            case CV_8UC3:
              format = QImage::Format_RGB888;
              break;
            case CV_8UC4:
              format = QImage::Format_ARGB32;
              break;
            }
            QImage img = QImage((const uchar*)m_srcImage.data, m_srcImage.cols, m_srcImage.rows,
            m_srcImage.cols * m_srcImage.channels(), format);
            img = img.scaled(ui->label->width(),ui->label->height(),Qt::IgnoreAspectRatio, Qt::SmoothTransformation);//图片自适应lab大小
            ui->label->setPixmap(QPixmap::fromImage(img));
        }
    }
    else if(msgList[msgList.size()-1]=="TIFF"||
            msgList[msgList.size()-1]=="tiff")
    {
        ui->widget->setVisible(false);
        ui->label->setVisible(true);
        cv::Mat m_fsrcImage = cv::imread(filename,cv::IMREAD_UNCHANGED);
        cv::Mat m_srcImage;
        if(m_fsrcImage.type()!=CV_32FC1)
            return;
        pclclass.cv_f32deepimg_to_show8deepimg(m_fsrcImage,&m_srcImage);
        if (m_srcImage.empty()==0)
        {
            cvtColor(m_srcImage, m_srcImage, cv::COLOR_BGR2RGB);//BGR转化为RGB
            QImage::Format format = QImage::Format_RGB888;
            switch (m_srcImage.type())
            {
            case CV_8UC1:
              format = QImage::Format_Indexed8;
              break;
            case CV_8UC3:
              format = QImage::Format_RGB888;
              break;
            case CV_8UC4:
              format = QImage::Format_ARGB32;
              break;
            }
            QImage img = QImage((const uchar*)m_srcImage.data, m_srcImage.cols, m_srcImage.rows,
            m_srcImage.cols * m_srcImage.channels(), format);
            img = img.scaled(ui->label->width(),ui->label->height(),Qt::IgnoreAspectRatio, Qt::SmoothTransformation);//图片自适应lab大小
            ui->label->setPixmap(QPixmap::fromImage(img));
        }
    }
    else if(msgList[msgList.size()-1]=="PCD"||
            msgList[msgList.size()-1]=="pcd")
    {
        ui->widget->setVisible(true);
        ui->label->setVisible(false);
        pcl::visualization::PCLVisualizer::Ptr viewer (new pcl::visualization::PCLVisualizer("viewer", false));
        ui->widget->SetRenderWindow(viewer->getRenderWindow());
        viewer->setupInteractor(ui->widget->GetInteractor(), ui->widget->GetRenderWindow());
        viewer->addCoordinateSystem();  //添加坐标系

        pcl::io::loadPCDFile<pcl::PointXYZ>(filename, *pclclould);

        pcl::PointCloud<pcl::PointXYZRGB>::Ptr rgbclould(new pcl::PointCloud<pcl::PointXYZRGB>);
        pcl::copyPointCloud(*pclclould,*rgbclould);//点云转换
        pclclass.updata_color_pclclould(&rgbclould,&rgbclould);

        viewer->removeAllPointClouds();
        viewer->removeAllShapes();
        viewer->addPointCloud(rgbclould);
        ui->widget->update();
    }
}
