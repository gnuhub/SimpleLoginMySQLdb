#-------------------------------------------------
#
# Project created by QtCreator 2013-03-19T14:25:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = loginMySql
TEMPLATE = app

QT += sql

SOURCES += main.cpp\
           loing.cpp \
           registerwindow.cpp\
    qkeccakhash/qkeccakhash.cpp \
    qkeccakhash/keccakimpl.cpp


HEADERS  += loing.h \
            qkeccakhash/qkeccakhash.h \
            registerwindow.h


FORMS    += loing.ui \
    registerwindow.ui


