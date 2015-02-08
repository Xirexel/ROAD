#-------------------------------------------------
#
# Project created by QtCreator 2015-02-09T00:22:58
#
#-------------------------------------------------

QT       -= core gui

TARGET = CRC
TEMPLATE = lib
CONFIG += staticlib
CONFIG += c++11

SOURCES += crc.cpp

HEADERS += crc.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
