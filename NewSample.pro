#-------------------------------------------------
#
# Project created by QtCreator 2016-10-10T13:08:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NewSample
TEMPLATE = app

INCLUDEPATH += /usr/local/include
LIBS += -L/usr/local/lib -lopencv_core -lopencv_imgcodecs -lopencv_highgui -lopencv_imgproc -lopencv_video  -lopencv_videoio  -lopencv_videostab


SOURCES += main.cpp\
        mainwindow.cpp \
    frame.cpp \
    imagepoint.cpp \
    video.cpp

HEADERS  += mainwindow.h \
    frame.h \
    imagepoint.h \
    video.h

FORMS    += mainwindow.ui
