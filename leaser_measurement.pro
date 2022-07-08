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
    cam_sen.h \
    global.h \
    leaser_measurementdlg.h \
    leaser_showpointdlg.h \
    my_parameters.h \
    soptopcamera.h

#opencv库的添加
INCLUDEPATH += /usr/local/OpenCV/Release/include/opencv4 \

LIBS += /usr/local/OpenCV/Release/lib/libopencv_*
