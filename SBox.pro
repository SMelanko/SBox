#-------------------------------------------------
#
# Project created by QtCreator 2015-09-26T14:08:52
#
#-------------------------------------------------

QT       += core gui

CONFIG += c++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SBox
TEMPLATE = app

SOURCES += main.cpp\
    SBox.cpp \
    MsgBox.cpp \
    InfoBox.cpp \
    ErrorBox.cpp

HEADERS  += SBox.h \
    MsgBox.h \
    InfoBox.h \
    ErrorBox.h

RESOURCES += \
    Res.qrc
