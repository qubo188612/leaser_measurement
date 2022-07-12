#include "leaser_showpointdlg.h"
#include "ui_leaser_showpointdlg.h"

leaser_showpointdlg::leaser_showpointdlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::leaser_showpointdlg)
{
    ui->setupUi(this);
}

leaser_showpointdlg::~leaser_showpointdlg()
{
    delete ui;
}

void leaser_showpointdlg::showpoint(std::string filename)
{
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
        ui->label->clear();
        QPixmap pixmap = QPixmap::fromImage(img);
        pixmap = pixmap.scaled(ui->label->size());
        ui->label->setAutoFillBackground(true);
        QPalette palette;
        palette.setBrush(ui->label->backgroundRole(), QBrush(pixmap));
        ui->label->setPalette(palette);
        ui->label->repaint();
    }
}
