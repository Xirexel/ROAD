#-------------------------------------------------
#
# Project created by QtCreator 2014-12-02T10:07:36
#
#-------------------------------------------------

QT       -= gui

TARGET = Driver
TEMPLATE = lib
CONFIG += c++11

DLLDESTDIR = ../../Bin/ROADdecoder ../../Bin/ROADPlayer

DEFINES += DRIVER_LIBRARY

SOURCES += \
    DataReadDriver.cpp \
    DataDriver.cpp \
    IDataReadDriver.cpp

HEADERS +=\
        driver_global.h \
    DataReadDriver.h \
    DataDriver.h \
    IDataReadDriver.h



win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Endian/release/ -lEndian
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Endian/debug/ -lEndian
else:unix: LIBS += -L$$OUT_PWD/../Endian/ -lEndian

INCLUDEPATH += $$PWD/../Endian
DEPENDPATH += $$PWD/../Endian
