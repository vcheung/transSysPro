#-------------------------------------------------
#
# Project created by QtCreator 2013-11-19T09:11:26
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = A8
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    workwidget.cpp \
    myinputpanelcontext.cpp \
    secretinput.cpp \
    myinputpanel.cpp

HEADERS  += widget.h \
    workwidget.h \
    myinputpanelcontext.h \
    secretinput.h \
    myinputpanel.h \
    confi.h

FORMS    += widget.ui \
    workwidget.ui \
    secretinput.ui \
    myinputpanelform.ui
