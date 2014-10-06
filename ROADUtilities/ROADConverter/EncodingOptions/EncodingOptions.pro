#-------------------------------------------------
#
# Project created by QtCreator 2014-12-31T15:45:00
#
#-------------------------------------------------

QT       -= gui

TARGET = EncodingOptions
TEMPLATE = lib
CONFIG += c++11

win32:DLLDESTDIR = ../../../Bin/ROADConverter
else:unix:DESTDIR = ../../../Bin/ROADConverter

DEFINES += ENCODINGOPTIONS_LIBRARY

SOURCES += \
    encodingoptionsfactory.cpp \
    persistroadencodingoptions.cpp

HEADERS +=\
        encodingoptions_global.h \
    encodingoptionsfactory.h \
    persistroadencodingoptions.h




win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../../ROADcodec/ROADcoder/ROADoverCoder/release/ -lROADoverCoder
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../../ROADcodec/ROADcoder/ROADoverCoder/debug/ -lROADoverCoder
else:unix: LIBS += -L$$OUT_PWD/../../../Bin/ROADcoder/ -lROADoverCoder

INCLUDEPATH += $$PWD/../../../ROADcodec/ROADcoder/ROADoverCoder
DEPENDPATH += $$PWD/../../../ROADcodec/ROADcoder/ROADoverCoder
