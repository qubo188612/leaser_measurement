#ifndef LEASER_SHOWPOINTDLG_H
#define LEASER_SHOWPOINTDLG_H

#include <QDialog>
#include <QFileDialog>
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    #include <QtCore/QTextCodec>
#else
    #include <QtCore5Compat/QTextCodec>
#endif
#include "opencv2/opencv.hpp"
#include "MyPlcFunction.h"

namespace Ui {
class leaser_showpointdlg;
}

class leaser_showpointdlg : public QDialog
{
    Q_OBJECT

public:
    explicit leaser_showpointdlg(QWidget *parent = nullptr);
    ~leaser_showpointdlg();

    void showpoint(std::string filename);      //显示图像

    Ui::leaser_showpointdlg *ui;

    pcl::PointCloud<pcl::PointXYZ>::Ptr pclclould;    //点云
private:
    MyPlcFunction pclclass;//点云算法
};

#endif // LEASER_SHOWPOINTDLG_H
