#include <QApplication>
#include <leaser_measurementdlg.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    leaser_measurementDlg main_window;
    main_window.m_mcs->cam->sop_cam[0].argc=argc;
    main_window.m_mcs->cam->sop_cam[0].argv=argv;
    main_window.setWindowTitle("3D轮廓激光测量");
    main_window.show();
    return a.exec();
}
