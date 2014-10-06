#-------------------------------------------------
#
# Project created by QtCreator 2014-12-14T22:24:55
#
#-------------------------------------------------

QT       -= gui

TARGET = ROADCoder
TEMPLATE = lib
CONFIG += c++11

win32:DLLDESTDIR = ../../../Bin/ROADcoder ../../../Bin/ROADConverter
else:unix:DESTDIR = ../../../Bin/ROADcoder

DEFINES += ROADCODER_LIBRARY

SOURCES += \
    Domain.cpp \
    DomainPool.cpp \
    ROADOrderedFractalAnalyzerFactory.cpp \
    ROADFractalFirstOrderAnalyzerNoneFixedRangLength.cpp \
    ROADFractalFirstOrderAnalyzerFactory.cpp

HEADERS +=\
    Domain.h \
    DomainPool.h \
    IFractalAverItem.h \
    IFractalEncodingOptions.h \
    IROADFractalAnalyzerFactory.h \
    ROADOrderedFractalAnalyzerFactory.h \
    IFractalFirstOrderItem.h \
    IFractalFirstOrderItemContainer.h \
    IROADFractalFirstOrderAnalyzer.h \
    ROADFractalFirstOrderAnalyzerFactory.h \
    ROADFractalFirstOrderAnalyzerNoneFixedRangLength.h


