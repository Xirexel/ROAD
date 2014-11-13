#-------------------------------------------------
#
# Project created by QtCreator 2014-11-13T16:13:40
#
#-------------------------------------------------

QT       -= gui

TARGET = Endian
TEMPLATE = lib
CONFIG += c++11

DLLDESTDIR = ../../Bin/ROADdecoder

DEFINES += ENDIAN_LIBRARY

SOURCES += endian.cpp \
    BigEndianConvertor.cpp \
    EndianConvertor.cpp \
    IConvertor.cpp \
    LittleEndianConvertor.cpp

HEADERS += endian.h\
        endian_global.h \
    BigEndianConvertor.h \
    EndianConvertor.h \
    IConvertor.h \
    LittleEndianConvertor.h

