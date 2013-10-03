#-------------------------------------------------
#
# Project created by QtCreator 2013-03-19T14:25:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = loginMySql
TEMPLATE = app


SOURCES += main.cpp\
        loing.cpp \
    registerwindow.cpp
    QT += sql
HEADERS  += loing.h \
    registerwindow.h

FORMS    += loing.ui \
    registerwindow.ui


