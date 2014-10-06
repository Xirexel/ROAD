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
    Domain.cpp \
    DomainPool.cpp \
    DoubleDataContainer.cpp \
    FractalDataContainer.cpp \
    FractalEncoder.cpp \
    FractalItem.cpp \
    FrameFractalItemCollection.cpp \
    IDomain.cpp \
    IDoubleDataContainer.cpp \
    IFractalItem.cpp \
    IFrameFractalItemCollection.cpp \
    IUCharDataContainer.cpp \
    ROAD_Encoder.cpp \
    ROADEncodingOptions.cpp \
    SuperFrameFractalItemCollection.cpp \
    UCharDataContainer.cpp \
    IROADDataContainer.cpp

HEADERS +=\
        roadcoder_global.h \
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
    IUCharDataContainer.h \
    ROAD_Encoder.h \
    ROADEncodingOptions.h \
    SuperFrameFractalItemCollection.h \
    UCharDataContainer.h \
    IROADDataContainer.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
