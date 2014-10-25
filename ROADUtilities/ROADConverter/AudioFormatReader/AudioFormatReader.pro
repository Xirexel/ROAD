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

DLLDESTDIR = ../../../Bin/ROADConverter

DEFINES += AUDIOFORMATREADER_LIBRARY

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

unix {
    target.path = /usr/lib
    INSTALLS += target
}
