#-------------------------------------------------
#
# Project created by QtCreator 2014-11-05T11:52:47
#
#-------------------------------------------------

QT       -= gui

TARGET = ROAD
TEMPLATE = lib
CONFIG += c++11

win32:DLLDESTDIR = ../../../Bin/ROADdecoder ../../../Bin/ROADPlayer
else:unix:DESTDIR = ../../../Bin/ROADdecoder

DEFINES += ROAD_LIBRARY

SOURCES += \
    ROADFractalBuilderNoneFixedRangLength.cpp \
    ROADFractalFirstOrderBuilderFactory.cpp \
    DomainProcessorFirstOrderNoneFixedLength.cpp \
    ROADFractalOrderFactory.cpp

HEADERS +=\
    IFractalAverItem.h \
    ROADFractalFirstOrderBuilderFactory.h \
    ROADFractalFirstOrderBuilderNoneFixedRangLength.h \
    IROADFractalFirstOrderBuilder.h \
    IFractalFirstOrderItemContainer.h \
    IFractalFirstOrderItem.h \
    DomainProcessorFirstOrderNoneFixedLength.h \
    IROADFractalBuilderFactory.h \
    ROADFractalOrderFactory.h
