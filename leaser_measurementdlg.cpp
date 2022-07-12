#include "leaser_measurementdlg.h"
#include "ui_leaser_measurementdlg.h"


leaser_measurementDlg::leaser_measurementDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::leaser_measurementDlg)
{
    m_mcs=m_mcs->Get();

    ui->setupUi(this);

    imgshow_thread = new ImgWindowShowThread(this);
    connect(imgshow_thread, SIGNAL(Send_show_image()), this, SLOT(init_send_show_image()));

    imgshow_thread->start();

    connect(ui->connectcamBtn,&QPushButton::clicked,[=](){
       if(m_mcs->cam->sop_cam[0].b_connect==false)
       {
          img_windowshow(true);
          ui->connectcamBtn->setText("断开");
       }
       else
       {
         img_windowshow(false);
         ui->connectcamBtn->setText("连接");
       }
    });

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

void leaser_measurementDlg::img_windowshow(bool b_show)
{
    if(b_show==true)
    {
        m_mcs->cam->sop_cam[0].InitConnect();
    }
    else
    {
        m_mcs->cam->sop_cam[0].DisConnect();
    }
}

void leaser_measurementDlg::init_send_show_image()
{
    cv::Mat m_srcImage=(*m_mcs->cam->sop_cam[0].cv_image).clone();
//  cvtColor(m_srcImage, m_srcImage, cv::COLOR_BGR2RGB);//BGR转化为RGB
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
    ui->label->clear();
    QPixmap pixmap = QPixmap::fromImage(img);
    pixmap = pixmap.scaled(ui->label->size());
    ui->label->setAutoFillBackground(true);
    QPalette palette;
    palette.setBrush(ui->label->backgroundRole(), QBrush(pixmap));
    ui->label->setPalette(palette);
    ui->label->repaint();
}

ImgWindowShowThread::ImgWindowShowThread(leaser_measurementDlg *statci_p)
{
    _p=statci_p;
}

void ImgWindowShowThread::run()
{
    while(1)
    {
        if(_p->m_mcs->cam->sop_cam[0].cv_image->empty()==0)
        {
            emit Send_show_image();
        }
        sleep(1);
    }
}
