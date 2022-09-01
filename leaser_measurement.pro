QT -= gui

CONFIG += c++17 console
CONFIG -= app_bundle

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 5): QT += core5compat
QT       += core gui network

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        E2proomData.cpp \
        FileOut.cpp \
        MyPlcFunction.cpp \
        ResultData.cpp \
        TimeFunction.cpp \
        cam_sen.cpp \
        leaser_measurementdlg.cpp \
        leaser_showpointdlg.cpp \
        main.cpp \
        my_parameters.cpp \
        soptopcamera.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    leaser_measurementdlg.ui \
    leaser_showpointdlg.ui

HEADERS += \
    E2proomData.h \
    FileOut.h \
    MyPlcFunction.h \
    ResultData.h \
    TimeFunction.h \
    cam_sen.h \
    global.h \
    leaser_measurementdlg.h \
    leaser_showpointdlg.h \
    my_parameters.h \
    soptopcamera.h \
    tistdtypes.h

#opencv库的添加
INCLUDEPATH += /usr/local/OpenCV/Release/include/opencv4 \

LIBS += /usr/local/OpenCV/Release/lib/libopencv_*

#ROS库添加
INCLUDEPATH +=/opt/ros/galactic/include \

LIBS += /opt/ros/galactic/lib/lib*.so
LIBS += /opt/ros/galactic/lib/x86_64-linux-gnu/lib*.so


#Eigen库
INCLUDEPATH += /usr/include/eigen3

#VTK库添加
INCLUDEPATH +=/usr/local/include/vtk-7.1 \

LIBS += /usr/local/lib/libvtk*

#Boost
INCLUDEPATH += /usr/include/boost

LIBS += /usr/lib/x86_64-linux-gnu/libboost_*.so

#PCL库添加
INCLUDEPATH +=/usr/local/include/pcl-1.12 \

LIBS += /usr/local/lib/libpcl_*

#modbustcp库的添加
INCLUDEPATH += /home/qubo/modbus/libmodbus/install/include \

LIBS += /home/qubo/modbus/libmodbus/install/lib/libmodbus.so

#自定义ROS接口添加
INCLUDEPATH +=/home/qubo/myRos2test/install/tutorial_interfaces/include \

LIBS += /home/qubo/myRos2test/install/tutorial_interfaces/lib/libtutorial_interfaces*.so



