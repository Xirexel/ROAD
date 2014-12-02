#-------------------------------------------------
#
# Project created by QtCreator 2014-10-18T14:21:16
#
#-------------------------------------------------

QT       -=  gui

TARGET = ROADoverWAVE
TEMPLATE = lib
CONFIG += staticlib
CONFIG += c++11

#DLLDESTDIR = ../../Bin/ROADPlayer

DEFINES += ROADOVER_LIBRARY

SOURCES += roadoverwave.cpp \
    wavefractal_parser.cpp

HEADERS += roadoverwave.h \
    wavefractal_parser.h



win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../../ROADcodec/ROADdecoder/ROADover/release/ -lROADover
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../../ROADcodec/ROADdecoder/ROADover/debug/ -lROADover
else:unix: LIBS += -L$$OUT_PWD/../../../ROADcodec/ROADdecoder/ROADover/ -lROADover

INCLUDEPATH += $$PWD/../../../ROADcodec/ROADdecoder/ROADover
DEPENDPATH += $$PWD/../../../ROADcodec/ROADdecoder/ROADover
