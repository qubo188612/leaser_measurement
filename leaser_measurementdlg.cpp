#include "leaser_measurementdlg.h"
#include "ui_leaser_measurementdlg.h"


leaser_measurementDlg::leaser_measurementDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::leaser_measurementDlg)
{
    m_mcs=m_mcs->Get();
    ui->setupUi(this);

    connect(ui->openpointfileBtn,&QPushButton::clicked,[=](){

        QString fileName = QFileDialog::getOpenFileName(this, "open Image", "", "Image File(*.bmp *.jpg *.jpeg *.png)");
        QTextCodec* code = QTextCodec::codecForName("gb18030");
        std::string name = code->fromUnicode(fileName).data();
        if(name.size()>0)
        {
            showpoint.setWindowTitle("点云图像");
            showpoint.show();
            showpoint.showpoint(name);
        }
    });
}

leaser_measurementDlg::~leaser_measurementDlg()
{
    delete ui;
}

void leaser_measurementDlg::img_windowshow()
{

}
