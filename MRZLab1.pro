#-------------------------------------------------
#
# Project created by QtCreator 2013-01-29T20:05:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MRZLab1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    binnumber.cpp \
    device.cpp \
    shiftsummdevice.cpp \
    conveyor.cpp

HEADERS  += mainwindow.h \
    defines.h \
    binnumber.h \
    device.h \
    shiftsummdevice.h \
    conveyor.h

FORMS    += mainwindow.ui
