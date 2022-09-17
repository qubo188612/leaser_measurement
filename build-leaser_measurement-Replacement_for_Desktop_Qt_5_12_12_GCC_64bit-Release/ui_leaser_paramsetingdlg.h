/********************************************************************************
** Form generated from reading UI file 'leaser_paramsetingdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEASER_PARAMSETINGDLG_H
#define UI_LEASER_PARAMSETINGDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_leaser_paramsetingdlg
{
public:
    QTabWidget *tabWidget;
    QWidget *tab;
    QTableWidget *tab1tableWidget;
    QPushButton *readTab1Btn;
    QPushButton *writeTab1Btn;
    QPushButton *initTab1Btn;
    QWidget *tab_2;
    QTableWidget *tab2tableWidget;
    QPushButton *initTab2Btn;
    QPushButton *writeTab2Btn;
    QPushButton *readTab2Btn;
    QTextBrowser *record;
    QLabel *label;

    void setupUi(QDialog *leaser_paramsetingdlg)
    {
        if (leaser_paramsetingdlg->objectName().isEmpty())
            leaser_paramsetingdlg->setObjectName(QString::fromUtf8("leaser_paramsetingdlg"));
        leaser_paramsetingdlg->resize(532, 489);
        tabWidget = new QTabWidget(leaser_paramsetingdlg);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(20, 20, 491, 301));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tab1tableWidget = new QTableWidget(tab);
        if (tab1tableWidget->columnCount() < 3)
            tab1tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tab1tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tab1tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tab1tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (tab1tableWidget->rowCount() < 7)
            tab1tableWidget->setRowCount(7);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tab1tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tab1tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tab1tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tab1tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tab1tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tab1tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tab1tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tab1tableWidget->setItem(0, 0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tab1tableWidget->setItem(0, 1, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tab1tableWidget->setItem(0, 2, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tab1tableWidget->setItem(1, 0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tab1tableWidget->setItem(1, 1, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tab1tableWidget->setItem(1, 2, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tab1tableWidget->setItem(2, 0, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tab1tableWidget->setItem(2, 1, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tab1tableWidget->setItem(2, 2, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tab1tableWidget->setItem(3, 0, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tab1tableWidget->setItem(3, 1, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tab1tableWidget->setItem(3, 2, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tab1tableWidget->setItem(4, 0, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tab1tableWidget->setItem(4, 1, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tab1tableWidget->setItem(4, 2, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tab1tableWidget->setItem(5, 0, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tab1tableWidget->setItem(5, 1, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tab1tableWidget->setItem(5, 2, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tab1tableWidget->setItem(6, 0, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tab1tableWidget->setItem(6, 1, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tab1tableWidget->setItem(6, 2, __qtablewidgetitem30);
        tab1tableWidget->setObjectName(QString::fromUtf8("tab1tableWidget"));
        tab1tableWidget->setGeometry(QRect(10, 10, 311, 241));
        tab1tableWidget->verticalHeader()->setVisible(false);
        readTab1Btn = new QPushButton(tab);
        readTab1Btn->setObjectName(QString::fromUtf8("readTab1Btn"));
        readTab1Btn->setGeometry(QRect(330, 140, 151, 51));
        writeTab1Btn = new QPushButton(tab);
        writeTab1Btn->setObjectName(QString::fromUtf8("writeTab1Btn"));
        writeTab1Btn->setGeometry(QRect(330, 200, 151, 51));
        initTab1Btn = new QPushButton(tab);
        initTab1Btn->setObjectName(QString::fromUtf8("initTab1Btn"));
        initTab1Btn->setGeometry(QRect(330, 10, 151, 51));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tab2tableWidget = new QTableWidget(tab_2);
        if (tab2tableWidget->columnCount() < 3)
            tab2tableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tab2tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tab2tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tab2tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem33);
        if (tab2tableWidget->rowCount() < 2)
            tab2tableWidget->setRowCount(2);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tab2tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        tab2tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        tab2tableWidget->setItem(0, 0, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        tab2tableWidget->setItem(0, 1, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        tab2tableWidget->setItem(0, 2, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        tab2tableWidget->setItem(1, 0, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        tab2tableWidget->setItem(1, 1, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        tab2tableWidget->setItem(1, 2, __qtablewidgetitem41);
        tab2tableWidget->setObjectName(QString::fromUtf8("tab2tableWidget"));
        tab2tableWidget->setGeometry(QRect(10, 10, 311, 241));
        tab2tableWidget->verticalHeader()->setVisible(false);
        initTab2Btn = new QPushButton(tab_2);
        initTab2Btn->setObjectName(QString::fromUtf8("initTab2Btn"));
        initTab2Btn->setGeometry(QRect(330, 10, 151, 51));
        writeTab2Btn = new QPushButton(tab_2);
        writeTab2Btn->setObjectName(QString::fromUtf8("writeTab2Btn"));
        writeTab2Btn->setGeometry(QRect(330, 200, 151, 51));
        readTab2Btn = new QPushButton(tab_2);
        readTab2Btn->setObjectName(QString::fromUtf8("readTab2Btn"));
        readTab2Btn->setGeometry(QRect(330, 140, 151, 51));
        tabWidget->addTab(tab_2, QString());
        record = new QTextBrowser(leaser_paramsetingdlg);
        record->setObjectName(QString::fromUtf8("record"));
        record->setGeometry(QRect(20, 360, 491, 121));
        label = new QLabel(leaser_paramsetingdlg);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 330, 67, 17));

        retranslateUi(leaser_paramsetingdlg);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(leaser_paramsetingdlg);
    } // setupUi

    void retranslateUi(QDialog *leaser_paramsetingdlg)
    {
        leaser_paramsetingdlg->setWindowTitle(QApplication::translate("leaser_paramsetingdlg", "Dialog", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tab1tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("leaser_paramsetingdlg", "\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tab1tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("leaser_paramsetingdlg", "\345\217\226\345\200\274\350\214\203\345\233\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tab1tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("leaser_paramsetingdlg", "\345\200\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tab1tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("leaser_paramsetingdlg", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tab1tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("leaser_paramsetingdlg", "2", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tab1tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem5->setText(QApplication::translate("leaser_paramsetingdlg", "3", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tab1tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem6->setText(QApplication::translate("leaser_paramsetingdlg", "4", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tab1tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem7->setText(QApplication::translate("leaser_paramsetingdlg", "5", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tab1tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem8->setText(QApplication::translate("leaser_paramsetingdlg", "6", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tab1tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem9->setText(QApplication::translate("leaser_paramsetingdlg", "7", nullptr));

        const bool __sortingEnabled = tab1tableWidget->isSortingEnabled();
        tab1tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem10 = tab1tableWidget->item(0, 0);
        ___qtablewidgetitem10->setText(QApplication::translate("leaser_paramsetingdlg", "\344\272\214\345\200\274\345\214\226\351\230\210\345\200\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tab1tableWidget->item(0, 1);
        ___qtablewidgetitem11->setText(QApplication::translate("leaser_paramsetingdlg", "[0,255]", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tab1tableWidget->item(1, 0);
        ___qtablewidgetitem12->setText(QApplication::translate("leaser_paramsetingdlg", "\347\273\206\345\214\226\351\230\210\345\200\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tab1tableWidget->item(1, 1);
        ___qtablewidgetitem13->setText(QApplication::translate("leaser_paramsetingdlg", "[0,255]", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tab1tableWidget->item(2, 0);
        ___qtablewidgetitem14->setText(QApplication::translate("leaser_paramsetingdlg", "\345\256\275\345\272\246\350\277\236\351\200\232\350\267\235\347\246\273", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tab1tableWidget->item(2, 1);
        ___qtablewidgetitem15->setText(QApplication::translate("leaser_paramsetingdlg", "[0,255]", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tab1tableWidget->item(3, 0);
        ___qtablewidgetitem16->setText(QApplication::translate("leaser_paramsetingdlg", "\351\253\230\345\272\246\350\277\236\351\200\232\350\267\235\347\246\273", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tab1tableWidget->item(3, 1);
        ___qtablewidgetitem17->setText(QApplication::translate("leaser_paramsetingdlg", "[0,255]", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tab1tableWidget->item(4, 0);
        ___qtablewidgetitem18->setText(QApplication::translate("leaser_paramsetingdlg", "\346\273\244\346\263\242\350\267\235\347\246\273", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tab1tableWidget->item(4, 1);
        ___qtablewidgetitem19->setText(QApplication::translate("leaser_paramsetingdlg", "[0,255]", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tab1tableWidget->item(5, 0);
        ___qtablewidgetitem20->setText(QApplication::translate("leaser_paramsetingdlg", "\346\277\200\345\205\211\345\256\275\345\272\246\351\231\220\345\210\266", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tab1tableWidget->item(5, 1);
        ___qtablewidgetitem21->setText(QApplication::translate("leaser_paramsetingdlg", "[0,255]", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tab1tableWidget->item(6, 0);
        ___qtablewidgetitem22->setText(QApplication::translate("leaser_paramsetingdlg", "\346\277\200\345\205\211\345\257\271\346\257\224\345\272\246", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tab1tableWidget->item(6, 1);
        ___qtablewidgetitem23->setText(QApplication::translate("leaser_paramsetingdlg", "[0,255]", nullptr));
        tab1tableWidget->setSortingEnabled(__sortingEnabled);

        readTab1Btn->setText(QApplication::translate("leaser_paramsetingdlg", "\350\257\273\345\217\226\347\233\270\346\234\272\345\217\202\346\225\260", nullptr));
        writeTab1Btn->setText(QApplication::translate("leaser_paramsetingdlg", "\345\206\231\345\205\245\347\233\270\346\234\272\345\217\202\346\225\260", nullptr));
        initTab1Btn->setText(QApplication::translate("leaser_paramsetingdlg", "\351\207\215\347\275\256\347\233\270\346\234\272\345\217\202\346\225\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("leaser_paramsetingdlg", "Tab 1", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tab2tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem24->setText(QApplication::translate("leaser_paramsetingdlg", "\345\220\215\347\247\260", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tab2tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem25->setText(QApplication::translate("leaser_paramsetingdlg", "\345\217\226\345\200\274\350\214\203\345\233\264", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tab2tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem26->setText(QApplication::translate("leaser_paramsetingdlg", "\345\200\274", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tab2tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem27->setText(QApplication::translate("leaser_paramsetingdlg", "1", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = tab2tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem28->setText(QApplication::translate("leaser_paramsetingdlg", "2", nullptr));

        const bool __sortingEnabled1 = tab2tableWidget->isSortingEnabled();
        tab2tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem29 = tab2tableWidget->item(0, 0);
        ___qtablewidgetitem29->setText(QApplication::translate("leaser_paramsetingdlg", "\346\250\252\345\220\221\346\217\222\345\200\274(mm)", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = tab2tableWidget->item(0, 1);
        ___qtablewidgetitem30->setText(QApplication::translate("leaser_paramsetingdlg", "[0,255]", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = tab2tableWidget->item(1, 0);
        ___qtablewidgetitem31->setText(QApplication::translate("leaser_paramsetingdlg", "\347\272\265\345\220\221\346\217\222\345\200\274(mm)", nullptr));
        QTableWidgetItem *___qtablewidgetitem32 = tab2tableWidget->item(1, 1);
        ___qtablewidgetitem32->setText(QApplication::translate("leaser_paramsetingdlg", "[0,255]", nullptr));
        tab2tableWidget->setSortingEnabled(__sortingEnabled1);

        initTab2Btn->setText(QApplication::translate("leaser_paramsetingdlg", "\351\207\215\347\275\256\346\217\222\345\200\274\345\217\202\346\225\260", nullptr));
        writeTab2Btn->setText(QApplication::translate("leaser_paramsetingdlg", "\345\206\231\345\205\245\346\217\222\345\200\274\345\217\202\346\225\260", nullptr));
        readTab2Btn->setText(QApplication::translate("leaser_paramsetingdlg", "\350\257\273\345\217\226\346\217\222\345\200\274\345\217\202\346\225\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("leaser_paramsetingdlg", "Tab 2", nullptr));
        label->setText(QApplication::translate("leaser_paramsetingdlg", "\350\260\203\350\257\225\344\277\241\346\201\257:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class leaser_paramsetingdlg: public Ui_leaser_paramsetingdlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEASER_PARAMSETINGDLG_H
