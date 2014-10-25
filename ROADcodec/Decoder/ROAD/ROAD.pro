#-------------------------------------------------
#
# Project created by QtCreator 2014-10-16T09:30:41
#
#-------------------------------------------------

QT       -= gui

TARGET = ROAD
TEMPLATE = lib

DLLDESTDIR = ../../../Bin/ROAD/Decoder


DEFINES += ROAD_LIBRARY


unix {
    target.path = /usr/lib
    INSTALLS += target
}



HEADERS += \
    DomainProcessor.h \
    FractalItem.h \
    FractalItemContainer.h \
    IDoubleDataBuffer.h \
    IFractalDataContainer.h \
    IFractalItem.h \
    IFractalItemContainer.h \
    road_global.h \
    ROADdecoder.h \
    ROADdecodingOptions.h \
    SuperFrameFractaItemCollection.h \
    IDoubleDataContainer.h \
    IUCharDataContainer.h \
    IUIntDataContainer.h

SOURCES += \
    DomainProcessor.cpp \
    FractalItem.cpp \
    FractalItemContainer.cpp \
    IDoubleDataBuffer.cpp \
    ROADdecoder.cpp \
    ROADdecodingOptions.cpp \
    SuperFrameFractaItemCollection.cpp
