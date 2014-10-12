#-------------------------------------------------
#
# Project created by QtCreator 2014-10-09T16:18:23
#
#-------------------------------------------------

QT       -= gui

TARGET = ROADoverWAVECoder
TEMPLATE = lib
CONFIG  += plugin
CONFIG += c++11

DLLDESTDIR = ../../../Bin

DEFINES += ROADOVERWAVECODER_LIBRARY

SOURCES += roadoverwavecoder.cpp

HEADERS += roadoverwavecoder.h\
        roadoverwavecoder_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../../ROADcodec/Coder/ROADoverCoder/release/ -lROADoverCoder
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../../ROADcodec/Coder/ROADoverCoder/debug/ -lROADoverCoder
else:unix: LIBS += -L$$OUT_PWD/../../../ROADcodec/Coder/ROADoverCoder/ -lROADoverCoder

INCLUDEPATH += $$PWD/../../../ROADcodec/Coder/ROADoverCoder
DEPENDPATH += $$PWD/../../../ROADcodec/Coder/ROADoverCoder
