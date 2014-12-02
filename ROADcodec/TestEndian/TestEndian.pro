#-------------------------------------------------
#
# Project created by QtCreator 2014-11-14T12:36:04
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_testendiantest
CONFIG   += console
CONFIG   -= app_bundle
CONFIG   += c++11

TEMPLATE = app


SOURCES += tst_testendiantest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Endian/release/ -lEndian
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Endian/debug/ -lEndian
else:unix: LIBS += -L$$OUT_PWD/../Endian/ -lEndian

INCLUDEPATH += $$PWD/../Endian
DEPENDPATH += $$PWD/../Endian
