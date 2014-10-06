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



unix {
    target.path = /usr/lib
    INSTALLS += target
}

HEADERS += \
    AROADover.h \
    CharDataContainer.h \
    CRCProcessor.h \
    DoubleDataContainer.h \
    EntropyCompression.h \
    IMixingChannels.h \
    IRawDataBuffer.h \
    IROADDataCollection.h \
    LminusRMixingChannels.h \
    LogPrintOut.h \
    LplusRMixingChannels.h \
    MixingChannelsMode.h \
    NoneMixingChannels.h \
    RawDataBuffer.h \
    Result.h \
    ROADDataCollection.h \
    ROADManager.h \
    roadovercoder_global.h \
    ROADoverEncodingOptions.h

SOURCES += \
    AROADover.cpp \
    CharDataContainer.cpp \
    CRCProcessor.cpp \
    DoubleDataContainer.cpp \
    EntropyCompression.cpp \
    IMixingChannels.cpp \
    IRawDataBuffer.cpp \
    IROADDataCollection.cpp \
    LminusRMixingChannels.cpp \
    LplusRMixingChannels.cpp \
    MixingChannelsMode.cpp \
    NoneMixingChannels.cpp \
    RawDataBuffer.cpp \
    Result.cpp \
    ROADDataCollection.cpp \
    ROADManager.cpp \
    ROADoverEncodingOptions.cpp
