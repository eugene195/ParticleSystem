#-------------------------------------------------
#
# Project created by QtCreator 2014-08-18T01:25:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Particles
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
        mainwindow.cpp \
    particle.cpp \
    emitter.cpp \
    emissionstorage.cpp \
    drawer.cpp \
    mathvector.cpp \
    systemmanager.cpp \
    mover.cpp \
    scenematrix.cpp

HEADERS  += mainwindow.h \
    particle.h \
    emitter.h \
    emissionstorage.h \
    drawer.h \
    mathvector.h \
    systemmanager.h \
    mover.h \
    field.h \
    scenematrix.h \
    context.h

FORMS    += mainwindow.ui
