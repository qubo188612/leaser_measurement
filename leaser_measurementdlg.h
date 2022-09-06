#ifndef LEASER_MEASUREMENTDLG_H
#define LEASER_MEASUREMENTDLG_H

#include <QDialog>
#include <QFileDialog>
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    #include <QtCore/QTextCodec>
#else
    #include <QtCore5Compat/QTextCodec>
#endif
#include <leaser_showpointdlg.h>
#include <leaser_paramsetingdlg.h>
#include <my_parameters.h>
#include "rclcpp/rclcpp.hpp"
#include <QThread>
#include <QLabel>
#include <QMutex>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/io.h>
#include <unistd.h>
#include <dirent.h>
#include "TimeFunction.h"
#include "MyPlcFunction.h"
#include "QMutex"

namespace Ui {
class leaser_measurementDlg;
}

class ImgWindowShowThread;

class leaser_measurementDlg : public QDialog
{
    Q_OBJECT

public:
    explicit leaser_measurementDlg(QWidget *parent = nullptr);
    ~leaser_measurementDlg();

    my_parameters *m_mcs;

    void img_windowshow(bool b_show,QLabel *lab_show);      //显示图像

    Ui::leaser_measurementDlg *ui;

    MyPlcFunction pclclass;//点云算法

    cv::Mat pImage;//要计算的图像
    std::vector<cv::Point3f> cv_line; //要计算的点云

    bool b_imgshow_thread;      //线程运行标记
    bool stop_b_imgshow_thread;  //是否成功断开线程

    bool u8_save_imgdata;     //保存图像
    QString save_imgdata_cvimage(cv::Mat cv_image);  //保存opencv类型图
    QString save_pcldata_pclclould(pcl::PointCloud<pcl::PointXYZRGB>::Ptr pclclould);                //保存点云

    void start_deepimg();         //开始采集深度图
    void stop_deepimg();          //停止采集深度

    volatile bool b_int_show_cvimage_inlab_finish;          //int_show_cvimage_inlab信号曹空闲

    volatile bool b_init_show_pclclould_list_finish;          //init_show_pclclould_list信号曹空闲

    volatile bool b_int_show_record_finish;

private:

    leaser_showpointdlg *showpoint;
    leaser_paramsetingdlg *paramset;

    ImgWindowShowThread *imgshow_thread;

    void UpdataUi();  //刷新控件显示和使能

    void InitSetEdit(); //初始化控件数字  

    QTimer *timer_tragetor_clould;      //轨迹进入点云的定时器

    void open_camer_modbus();
    void close_camer_modbus();

    void showupdata_tabWidget();

private slots:

    void int_show_cvimage_inlab(cv::Mat cv_image);        //在windowshowlib中显示cv_image
    void init_show_pclclould_list(pcl::PointCloud<pcl::PointXYZRGB>::Ptr pclclould);      //在QVTKWidgetlib中显示点云
    void int_show_record(QString msg);
    void slot_timer_tragetor_clould();      //轨迹进入点云的定时器中断函数
};

class ImgWindowShowThread : public QThread
{
    Q_OBJECT
public:
    ImgWindowShowThread(leaser_measurementDlg *statci_p);
    void Stop();
    void Lock();
    void unLock();
protected:
    void run();
private:
    leaser_measurementDlg *_p;
    bool lock;
signals:
    // 自定义信号
    void Send_show_record(QString msg);
    void Send_show_cvimage_inlab(cv::Mat cv_image);       //发送图像显示信号
    void Send_show_pclclould_list(pcl::PointCloud<pcl::PointXYZRGB>::Ptr pclclould);      //发送点云显示信号
};

#endif // LEASER_MEASUREMENTDLG_H
