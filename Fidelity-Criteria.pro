#-------------------------------------------------
#
# Project created by QtCreator 2014-04-19T20:11:06
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = Fidelity-Criteria
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp

INCLUDEPATH += /usr/include/opencv2

LIBS += -L/usr/lib
LIBS += -lopencv_core
LIBS += -lopencv_imgproc
LIBS += -lopencv_highgui
