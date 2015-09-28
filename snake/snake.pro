#-------------------------------------------------
#
# Project created by QtCreator 2015-09-27T14:03:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = snake
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    snake.cpp

HEADERS  += mainwindow.h \
    snake.h

FORMS    += mainwindow.ui

RESOURCES += \
    src.qrc
