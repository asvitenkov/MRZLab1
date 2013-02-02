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
    summator.cpp \
    repeater.cpp \
    shiftdevice.cpp \
    shiftsummdevice.cpp \
    conveyor.cpp \
    multiplicationdescriptor.cpp \
    abstractconveyor.cpp \
    iodescriptor.cpp

HEADERS  += mainwindow.h \
    defines.h \
    binnumber.h \
    device.h \
    summator.h \
    repeater.h \
    shiftdevice.h \
    shiftsummdevice.h \
    conveyor.h \
    multiplicationdescriptor.h \
    abstractconveyor.h \
    iodescriptor.h

FORMS    += mainwindow.ui
