#-------------------------------------------------
#
# Project created by QtCreator 2015-11-26T21:57:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Historial
TEMPLATE = app


SOURCES += main.cpp\
        ventanahistorial.cpp \
    ganador.cpp \
    nodo.cpp \
    lista.cpp \
    avl.cpp \
    nododoble.cpp

HEADERS  += ventanahistorial.h \
    ganador.h \
    nodo.h \
    lista.h \
    avl.h \
    nododoble.h

FORMS    += ventanahistorial.ui
