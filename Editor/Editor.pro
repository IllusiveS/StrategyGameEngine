#-------------------------------------------------
#
# Project created by QtCreator 2017-02-14T13:11:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Editor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ui/maptiledisplay.cpp

HEADERS  += mainwindow.h \
    ui/maptiledisplay.h

FORMS    += mainwindow.ui \
    ui/maptiledisplay.ui
