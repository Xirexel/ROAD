#-------------------------------------------------
#
# Project created by QtCreator 2014-10-04T23:46:01
#
#-------------------------------------------------

QT       -= gui

TARGET = ROADCoder
TEMPLATE = lib

DEFINES += ROADCODER_LIBRARY

SOURCES += roadcoder.cpp

HEADERS += roadcoder.h\
        roadcoder_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
