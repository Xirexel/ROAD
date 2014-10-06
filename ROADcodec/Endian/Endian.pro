#-------------------------------------------------
#
# Project created by QtCreator 2014-11-13T16:13:40
#
#-------------------------------------------------

QT       -= gui

TARGET = Endian
TEMPLATE = lib
CONFIG += staticlib
CONFIG += c++11

HEADERS +=\
    BigEndianConvertor.h \
    EndianConvertorFactory.h \
    EndianType.h \
    IEndianConvertor.h \
    LittleEndianConvertor.h \
    LocalEndianConvertor.h

SOURCES += \
    BigEndianConvertor.cpp \
    EndianConvertorFactory.cpp \
    LittleEndianConvertor.cpp \
    LocalEndianConvertor.cpp
