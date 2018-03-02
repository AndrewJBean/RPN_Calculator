#-------------------------------------------------
#
# Project created by QtCreator 2013-07-05T11:48:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Calc
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    cmdlist.cpp \
    rpn.cpp

HEADERS  += widget.h \
    cmdlist.h \
    rpn.h

FORMS    += widget.ui

QMAKE_LFLAGS += -F/System/Library/Frameworks -L/usr/lib
