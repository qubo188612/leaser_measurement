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
#include <my_parameters.h>
#include "rclcpp/rclcpp.hpp"
#include <QThread>

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

    void img_windowshow(bool b_show);      //显示图像

    Ui::leaser_measurementDlg *ui;
private:

    leaser_showpointdlg showpoint;

    ImgWindowShowThread *imgshow_thread;

private slots:
    void init_send_show_image();
};

class ImgWindowShowThread : public QThread
{
    Q_OBJECT
public:
    ImgWindowShowThread(leaser_measurementDlg *statci_p);
protected:
    void run();
private:
    leaser_measurementDlg *_p;

signals:
    // 自定义信号
    void Send_show_image();
};

#endif // LEASER_MEASUREMENTDLG_H
