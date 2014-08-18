#-------------------------------------------------
#
# Project created by QtCreator 2014-08-18T01:25:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Particles
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    particle.cpp \
    emitter.cpp \
    emissionstorage.cpp \
    emissionmanager.cpp \
    drawer.cpp

HEADERS  += mainwindow.h \
    particle.h \
    particleinfo.h \
    emitter.h \
    emissionstorage.h \
    emissionmanager.h \
    drawer.h

FORMS    += mainwindow.ui
