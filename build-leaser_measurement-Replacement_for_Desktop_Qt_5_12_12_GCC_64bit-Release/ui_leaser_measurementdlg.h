/********************************************************************************
** Form generated from reading UI file 'leaser_measurementdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEASER_MEASUREMENTDLG_H
#define UI_LEASER_MEASUREMENTDLG_H

#include <QVTKWidget.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_leaser_measurementDlg
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *connectcamBtn;
    QPushButton *openpointfileBtn;
    QPushButton *showcamimgBtn;
    QPushButton *showcontourBtn;
    QPushButton *showtragetorBtn;
    QPushButton *showdeepimgBth;
    QPushButton *showclouldpointBtn;
    QPushButton *saveshowBtn;
    QPushButton *paramsetBtn;
    QLabel *windowshowlib;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_4;
    QLineEdit *exposureEdit;
    QLabel *label_1;
    QLabel *label_2;
    QPushButton *write_cam_editBtn;
    QVTKWidget *pclshowlib;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout;
    QLabel *deepimg_label_1;
    QLineEdit *deepimg_Edit_2;
    QLineEdit *deepimg_Edit_1;
    QLabel *deepimg_label_3;
    QLabel *deepimg_label_2;
    QLabel *deepimg_label_4;
    QPushButton *deepimg_StartBtn;
    QTextBrowser *record;
    QLabel *label;
    QLineEdit *IPadd;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *deepimg_Edit_3;
    QLabel *label_5;

    void setupUi(QDialog *leaser_measurementDlg)
    {
        if (leaser_measurementDlg->objectName().isEmpty())
            leaser_measurementDlg->setObjectName(QString::fromUtf8("leaser_measurementDlg"));
        leaser_measurementDlg->resize(1152, 610);
        horizontalLayoutWidget = new QWidget(leaser_measurementDlg);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(240, 10, 779, 32));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        connectcamBtn = new QPushButton(horizontalLayoutWidget);
        connectcamBtn->setObjectName(QString::fromUtf8("connectcamBtn"));

        horizontalLayout->addWidget(connectcamBtn);

        openpointfileBtn = new QPushButton(horizontalLayoutWidget);
        openpointfileBtn->setObjectName(QString::fromUtf8("openpointfileBtn"));

        horizontalLayout->addWidget(openpointfileBtn);

        showcamimgBtn = new QPushButton(horizontalLayoutWidget);
        showcamimgBtn->setObjectName(QString::fromUtf8("showcamimgBtn"));

        horizontalLayout->addWidget(showcamimgBtn);

        showcontourBtn = new QPushButton(horizontalLayoutWidget);
        showcontourBtn->setObjectName(QString::fromUtf8("showcontourBtn"));

        horizontalLayout->addWidget(showcontourBtn);

        showtragetorBtn = new QPushButton(horizontalLayoutWidget);
        showtragetorBtn->setObjectName(QString::fromUtf8("showtragetorBtn"));

        horizontalLayout->addWidget(showtragetorBtn);

        showdeepimgBth = new QPushButton(horizontalLayoutWidget);
        showdeepimgBth->setObjectName(QString::fromUtf8("showdeepimgBth"));

        horizontalLayout->addWidget(showdeepimgBth);

        showclouldpointBtn = new QPushButton(horizontalLayoutWidget);
        showclouldpointBtn->setObjectName(QString::fromUtf8("showclouldpointBtn"));

        horizontalLayout->addWidget(showclouldpointBtn);

        saveshowBtn = new QPushButton(horizontalLayoutWidget);
        saveshowBtn->setObjectName(QString::fromUtf8("saveshowBtn"));

        horizontalLayout->addWidget(saveshowBtn);

        paramsetBtn = new QPushButton(horizontalLayoutWidget);
        paramsetBtn->setObjectName(QString::fromUtf8("paramsetBtn"));

        horizontalLayout->addWidget(paramsetBtn);

        windowshowlib = new QLabel(leaser_measurementDlg);
        windowshowlib->setObjectName(QString::fromUtf8("windowshowlib"));
        windowshowlib->setGeometry(QRect(240, 60, 911, 541));
        gridLayoutWidget = new QWidget(leaser_measurementDlg);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 60, 221, 121));
        gridLayout_4 = new QGridLayout(gridLayoutWidget);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        exposureEdit = new QLineEdit(gridLayoutWidget);
        exposureEdit->setObjectName(QString::fromUtf8("exposureEdit"));

        gridLayout_4->addWidget(exposureEdit, 0, 1, 1, 1);

        label_1 = new QLabel(gridLayoutWidget);
        label_1->setObjectName(QString::fromUtf8("label_1"));

        gridLayout_4->addWidget(label_1, 0, 0, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_4->addWidget(label_2, 0, 2, 1, 1);

        write_cam_editBtn = new QPushButton(gridLayoutWidget);
        write_cam_editBtn->setObjectName(QString::fromUtf8("write_cam_editBtn"));

        gridLayout_4->addWidget(write_cam_editBtn, 1, 0, 1, 3);

        pclshowlib = new QVTKWidget(leaser_measurementDlg);
        pclshowlib->setObjectName(QString::fromUtf8("pclshowlib"));
        pclshowlib->setGeometry(QRect(240, 60, 911, 541));
        gridLayoutWidget_2 = new QWidget(leaser_measurementDlg);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(10, 250, 221, 151));
        gridLayout = new QGridLayout(gridLayoutWidget_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        deepimg_label_1 = new QLabel(gridLayoutWidget_2);
        deepimg_label_1->setObjectName(QString::fromUtf8("deepimg_label_1"));

        gridLayout->addWidget(deepimg_label_1, 0, 0, 1, 1);

        deepimg_Edit_2 = new QLineEdit(gridLayoutWidget_2);
        deepimg_Edit_2->setObjectName(QString::fromUtf8("deepimg_Edit_2"));

        gridLayout->addWidget(deepimg_Edit_2, 1, 1, 1, 1);

        deepimg_Edit_1 = new QLineEdit(gridLayoutWidget_2);
        deepimg_Edit_1->setObjectName(QString::fromUtf8("deepimg_Edit_1"));

        gridLayout->addWidget(deepimg_Edit_1, 0, 1, 1, 1);

        deepimg_label_3 = new QLabel(gridLayoutWidget_2);
        deepimg_label_3->setObjectName(QString::fromUtf8("deepimg_label_3"));

        gridLayout->addWidget(deepimg_label_3, 1, 0, 1, 1);

        deepimg_label_2 = new QLabel(gridLayoutWidget_2);
        deepimg_label_2->setObjectName(QString::fromUtf8("deepimg_label_2"));

        gridLayout->addWidget(deepimg_label_2, 0, 2, 1, 1);

        deepimg_label_4 = new QLabel(gridLayoutWidget_2);
        deepimg_label_4->setObjectName(QString::fromUtf8("deepimg_label_4"));

        gridLayout->addWidget(deepimg_label_4, 1, 2, 1, 1);

        deepimg_StartBtn = new QPushButton(gridLayoutWidget_2);
        deepimg_StartBtn->setObjectName(QString::fromUtf8("deepimg_StartBtn"));

        gridLayout->addWidget(deepimg_StartBtn, 2, 0, 1, 3);

        record = new QTextBrowser(leaser_measurementDlg);
        record->setObjectName(QString::fromUtf8("record"));
        record->setGeometry(QRect(10, 460, 221, 141));
        label = new QLabel(leaser_measurementDlg);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 440, 67, 17));
        IPadd = new QLineEdit(leaser_measurementDlg);
        IPadd->setObjectName(QString::fromUtf8("IPadd"));
        IPadd->setGeometry(QRect(60, 10, 113, 25));
        label_3 = new QLabel(leaser_measurementDlg);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 10, 51, 17));
        label_4 = new QLabel(leaser_measurementDlg);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 210, 81, 17));
        deepimg_Edit_3 = new QLineEdit(leaser_measurementDlg);
        deepimg_Edit_3->setObjectName(QString::fromUtf8("deepimg_Edit_3"));
        deepimg_Edit_3->setGeometry(QRect(90, 210, 108, 25));
        label_5 = new QLabel(leaser_measurementDlg);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(200, 210, 31, 25));

        retranslateUi(leaser_measurementDlg);

        QMetaObject::connectSlotsByName(leaser_measurementDlg);
    } // setupUi

    void retranslateUi(QDialog *leaser_measurementDlg)
    {
        leaser_measurementDlg->setWindowTitle(QApplication::translate("leaser_measurementDlg", "Dialog", nullptr));
        connectcamBtn->setText(QApplication::translate("leaser_measurementDlg", "\350\277\236\346\216\245", nullptr));
        openpointfileBtn->setText(QApplication::translate("leaser_measurementDlg", "\346\211\223\345\274\200\347\202\271\344\272\221", nullptr));
        showcamimgBtn->setText(QApplication::translate("leaser_measurementDlg", "\346\230\276\347\244\272\345\216\237\345\233\276", nullptr));
        showcontourBtn->setText(QApplication::translate("leaser_measurementDlg", "\346\230\276\347\244\272\350\275\256\345\273\223", nullptr));
        showtragetorBtn->setText(QApplication::translate("leaser_measurementDlg", "\346\230\276\347\244\272\350\275\250\350\277\271", nullptr));
        showdeepimgBth->setText(QApplication::translate("leaser_measurementDlg", "\346\230\276\347\244\272\346\267\261\345\272\246", nullptr));
        showclouldpointBtn->setText(QApplication::translate("leaser_measurementDlg", "\346\230\276\347\244\272\347\202\271\344\272\221", nullptr));
        saveshowBtn->setText(QApplication::translate("leaser_measurementDlg", "\344\277\235\345\255\230\347\273\223\346\236\234", nullptr));
        paramsetBtn->setText(QApplication::translate("leaser_measurementDlg", "\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        windowshowlib->setText(QString());
        label_1->setText(QApplication::translate("leaser_measurementDlg", "\346\233\235\345\205\211", nullptr));
        label_2->setText(QApplication::translate("leaser_measurementDlg", "TextLabel", nullptr));
        write_cam_editBtn->setText(QApplication::translate("leaser_measurementDlg", "\345\272\224\347\224\250", nullptr));
        deepimg_label_1->setText(QApplication::translate("leaser_measurementDlg", "\351\207\207\346\240\267\350\267\235\347\246\273", nullptr));
        deepimg_label_3->setText(QApplication::translate("leaser_measurementDlg", "\351\207\207\346\240\267\351\200\237\345\272\246", nullptr));
        deepimg_label_2->setText(QApplication::translate("leaser_measurementDlg", "mm", nullptr));
        deepimg_label_4->setText(QApplication::translate("leaser_measurementDlg", "mm/s", nullptr));
        deepimg_StartBtn->setText(QApplication::translate("leaser_measurementDlg", "\344\270\200\351\224\256\351\207\207\351\233\206", nullptr));
        label->setText(QApplication::translate("leaser_measurementDlg", "\350\260\203\350\257\225\344\277\241\346\201\257:", nullptr));
        label_3->setText(QApplication::translate("leaser_measurementDlg", "IP\345\234\260\345\235\200:", nullptr));
        label_4->setText(QApplication::translate("leaser_measurementDlg", "\346\257\217\345\203\217\347\264\240\350\267\235\347\246\273:", nullptr));
        label_5->setText(QApplication::translate("leaser_measurementDlg", "mm", nullptr));
    } // retranslateUi

};

namespace Ui {
    class leaser_measurementDlg: public Ui_leaser_measurementDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEASER_MEASUREMENTDLG_H
