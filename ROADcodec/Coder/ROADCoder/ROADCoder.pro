#-------------------------------------------------
#
# Project created by QtCreator 2014-10-05T16:58:15
#
#-------------------------------------------------

QT       -= gui

TARGET = ROADCoder
TEMPLATE = lib
CONFIG += c++11

DLLDESTDIR = ../../../Bin

DEFINES += ROADCODER_LIBRARY

SOURCES += \
    DataBuffer.cpp \
    Domain.cpp \
    DomainPool.cpp \
    DoubleDataContainer.cpp \
    FractalDataContainer.cpp \
    FractalEncoder.cpp \
    FractalItem.cpp \
    FrameFractalItemCollection.cpp \
    IDomain.cpp \
    IDoubleDataContainer.cpp \
    IFractalDataContainer.cpp \
    IFractalItem.cpp \
    IFrameFractalItemCollection.cpp \
    IRawDataReader.cpp \
    IRawDataWriter.cpp \
    IUCharDataContainer.cpp \
    ReadResult.cpp \
    ROAD_Encoder.cpp \
    ROADEncodingOptions.cpp \
    SuperFrameFractalItemCollection.cpp \
    UCharDataContainer.cpp

HEADERS +=\
        roadcoder_global.h \
    DataBuffer.h \
    Domain.h \
    DomainPool.h \
    DoubleDataContainer.h \
    FractalDataContainer.h \
    FractalEncoder.h \
    FractalItem.h \
    FrameFractalItemCollection.h \
    IDomain.h \
    IDoubleDataContainer.h \
    IFractalDataContainer.h \
    IFractalItem.h \
    IFrameFractalItemCollection.h \
    IRawDataReader.h \
    IRawDataWriter.h \
    IUCharDataContainer.h \
    ReadResult.h \
    ROAD_Encoder.h \
    ROADEncodingOptions.h \
    SuperFrameFractalItemCollection.h \
    UCharDataContainer.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
