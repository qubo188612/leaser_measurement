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

namespace Ui {
class leaser_measurementDlg;
}

class leaser_measurementDlg : public QDialog
{
    Q_OBJECT

public:
    explicit leaser_measurementDlg(QWidget *parent = nullptr);
    ~leaser_measurementDlg();

    my_parameters *m_mcs;

    void img_windowshow();      //显示图像
private:
    Ui::leaser_measurementDlg *ui;

    leaser_showpointdlg showpoint;
};

#endif // LEASER_MEASUREMENTDLG_H
