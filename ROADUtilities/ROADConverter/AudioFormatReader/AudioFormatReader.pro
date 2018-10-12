#-------------------------------------------------
#
# Project created by QtCreator 2014-10-13T10:21:23
#
#-------------------------------------------------

QT       += multimedia

QT       -= gui

TARGET = AudioFormatReader
TEMPLATE = lib
CONFIG += c++11

win32:DLLDESTDIR = ../../../Bin/ROADConverter
else:unix:DESTDIR = ../../../Bin/ROADConverter

DLLDESTDIR = ../../../Bin/ROADConverter

DEFINES += AUDIOFORMATREADER_LIBRARY

INCLUDEPATH += $$PWD/../../../ROADcodec/ROADcoder/ROADoverCoder

SOURCES += \
    ireaderfactory.cpp \
    wave_parser.cpp \
    originalaudiostreamoptions.cpp

HEADERS +=\
        audioformatreader_global.h \
    ireaderfactory.h \
    wave_parser.h \
    WaveReader.h \
    ireader.h \
    originalaudiostreamoptions.h

