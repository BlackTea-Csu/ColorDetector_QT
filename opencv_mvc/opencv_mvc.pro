#-------------------------------------------------
#
# Project created by QtCreator 2018-06-11T21:24:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = opencv_mvc
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    colordetectorcontroller.cpp \
    colordectector.cpp

HEADERS  += mainwindow.h \
    opencv_process/ColorDetectorController.h \
    opencv_process/ColorDetector.h

FORMS    += mainwindow.ui

INCLUDEPATH += /usr/local/include \
                /usr/local/include/opencv \
                /usr/local/include/opencv2

LIBS += /usr/local/lib/libopencv_highgui.so \
        /usr/local/lib/libopencv_core.so    \
        /usr/local/lib/libopencv_imgproc.so \
        /usr/local/lib/libopencv_imgcodecs.so.3.1
