#-------------------------------------------------
#
# Project created by QtCreator 2014-10-05T17:15:55
#
#-------------------------------------------------

QT       -= gui

TARGET = ROADoverCoder
TEMPLATE = lib
CONFIG += c++11

DLLDESTDIR = ../../../Bin

DEFINES += ROADOVERCODER_LIBRARY

SOURCES += roadovercoder.cpp

HEADERS += roadovercoder.h\
        roadovercoder_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
