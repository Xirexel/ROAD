#-------------------------------------------------
#
# Project created by QtCreator 2014-10-18T14:21:16
#
#-------------------------------------------------

QT       -=  gui

TARGET = ROADoverWAVE
TEMPLATE = lib
CONFIG += staticlib

#DLLDESTDIR = ../../Bin/ROADPlayer

DEFINES += ROADOVER_LIBRARY

SOURCES += roadoverwave.cpp \
    wavefractal_parser.cpp

HEADERS += roadoverwave.h \
    wavefractal_parser.h \
    IReader.h




win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../../ROADcodec/Decoder/ROADover/release/ -lROADover
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../../ROADcodec/Decoder/ROADover/debug/ -lROADover
else:unix: LIBS += -L$$OUT_PWD/../../../ROADcodec/Decoder/ROADover/ -lROADover

INCLUDEPATH += $$PWD/../../../ROADcodec/Decoder/ROADover
DEPENDPATH += $$PWD/../../../ROADcodec/Decoder/ROADover
