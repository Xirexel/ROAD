#-------------------------------------------------
#
# Project created by QtCreator 2014-11-13T16:13:40
#
#-------------------------------------------------

QT       -= gui

TARGET = Endian
TEMPLATE = lib
CONFIG += c++11

DLLDESTDIR = ../../Bin/ROADdecoder ../../Bin/ROADPlayer

DEFINES += ENDIAN_LIBRARY

HEADERS +=\
        endian_global.h \
    BigEndianConvertor.h \
    EndianConvertorFactory.h \
    EndianType.h \
    IEndianConvertor.h \
    LittleEndianConvertor.h \
    LocalEndianConvertor.h

SOURCES += \
    BigEndianConvertor.cpp \
    EndianConvertorFactory.cpp \
    EndianType.cpp \
    IEndianConvertor.cpp \
    LittleEndianConvertor.cpp \
    LocalEndianConvertor.cpp
