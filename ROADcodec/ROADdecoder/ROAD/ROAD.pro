#-------------------------------------------------
#
# Project created by QtCreator 2014-11-05T11:52:47
#
#-------------------------------------------------

QT       -= gui

TARGET = ROAD
TEMPLATE = lib
CONFIG += c++11

DLLDESTDIR = ../../../Bin/ROADdecoder ../../../Bin/ROADPlayer

DEFINES += ROAD_LIBRARY

SOURCES += \
    DomainProcessorNoneFixedLength.cpp \
    ROADFractalBuilderNoneFixedRangLength.cpp \
    ROADFractalBuilderFactory.cpp

HEADERS +=\
        road_global.h \
    DomainProcessorNoneFixedLength.h \
    IFractalAverItem.h \
    IFractalItem.h \
    IFractalItemContainer.h \
    IROADFractalBuilder.h \
    ROADFractalBuilderNoneFixedRangLength.h \
    ROADFractalBuilderFactory.h
