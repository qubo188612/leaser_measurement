/********************************************************************************
** Form generated from reading UI file 'leaser_showpointdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEASER_SHOWPOINTDLG_H
#define UI_LEASER_SHOWPOINTDLG_H

#include <QVTKWidget.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_leaser_showpointdlg
{
public:
    QLabel *label;
    QVTKWidget *widget;

    void setupUi(QDialog *leaser_showpointdlg)
    {
        if (leaser_showpointdlg->objectName().isEmpty())
            leaser_showpointdlg->setObjectName(QString::fromUtf8("leaser_showpointdlg"));
        leaser_showpointdlg->resize(1018, 495);
        label = new QLabel(leaser_showpointdlg);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 1001, 481));
        widget = new QVTKWidget(leaser_showpointdlg);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 1001, 481));

        retranslateUi(leaser_showpointdlg);

        QMetaObject::connectSlotsByName(leaser_showpointdlg);
    } // setupUi

    void retranslateUi(QDialog *leaser_showpointdlg)
    {
        leaser_showpointdlg->setWindowTitle(QApplication::translate("leaser_showpointdlg", "Dialog", nullptr));
        label->setText(QApplication::translate("leaser_showpointdlg", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class leaser_showpointdlg: public Ui_leaser_showpointdlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEASER_SHOWPOINTDLG_H
