#-------------------------------------------------
#
# Project created by QtCreator 2014-11-05T11:53:07
#
#-------------------------------------------------

QT       -= gui

TARGET = ROADover
TEMPLATE = lib
CONFIG += c++11

DLLDESTDIR = ../../../Bin/ROADdecoder

DEFINES += ROADOVER_LIBRARY

SOURCES += \
    ChannelsMixingMode.cpp \
    DoubleDataContainer.cpp \
    FractalAverItem.cpp \
    FractalItem.cpp \
    FractalItemContainer.cpp \
    IChannelsMixing.cpp \
    IDoubleDataContainer.cpp \
    IRawDataBuffer.cpp \
    IROADoverDecodingOptions.cpp \
    IROADoverManager.cpp \
    MIDChannelsMixing.cpp \
    NoneChannelsMixing.cpp \
    RawDataBuffer.cpp \
    Result.cpp \
    ROADFormatMode.cpp \
    ROADoverDecodingOptionsExperemental.cpp \
    ROADoverDecodingOptionsFactory.cpp \
    ROADoverManager.cpp \
    ROADoverManagerExperemental.cpp \
    SIDEChannelsMixing.cpp \
    ROADover.cpp

HEADERS +=\
        roadover_global.h \
    ChannelsMixingMode.h \
    DoubleDataContainer.h \
    FractalAverItem.h \
    FractalItem.h \
    FractalItemContainer.h \
    IChannelsMixing.h \
    IDoubleDataContainer.h \
    IRawDataBuffer.h \
    IROADoverDecodingOptions.h \
    IROADoverManager.h \
    MIDChannelsMixing.h \
    NoneChannelsMixing.h \
    RawDataBuffer.h \
    Result.h \
    ROADFormatMode.h \
    ROADoverDecodingOptionsExperemental.h \
    ROADoverDecodingOptionsFactory.h \
    ROADoverManager.h \
    ROADoverManagerExperemental.h \
    SIDEChannelsMixing.h \
    ROADover.h


