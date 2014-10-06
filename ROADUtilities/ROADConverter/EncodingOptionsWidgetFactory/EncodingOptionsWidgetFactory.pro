#-------------------------------------------------
#
# Project created by QtCreator 2014-12-30T23:47:23
#
#-------------------------------------------------

QT       += widgets

TARGET = EncodingOptionsWidgetFactory
TEMPLATE = lib
CONFIG += c++11

win32:DLLDESTDIR = ../../../Bin/ROADConverter
else:unix:DESTDIR = ../../../Bin/ROADConverter

DEFINES += ENCODINGOPTIONSWIDGETFACTORY_LIBRARY

SOURCES += encodingoptionswidgetfactory.cpp \
    encodingoptionsexperementalwidget.cpp \
    encodingoptionswidget.cpp

HEADERS += encodingoptionswidgetfactory.h\
        encodingoptionswidgetfactory_global.h \
    encodingoptionsexperementalwidget.h \
    encodingoptionswidget.h


FORMS += \
    encodingoptionsexperementalwidget.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../../ROADcodec/ROADcoder/ROADoverCoder/release/ -lROADoverCoder
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../../ROADcodec/ROADcoder/ROADoverCoder/debug/ -lROADoverCoder
else:unix: LIBS += -L$$OUT_PWD/../../../Bin/ROADcoder/ -lROADoverCoder

INCLUDEPATH += $$PWD/../../../ROADcodec/ROADcoder/ROADoverCoder
DEPENDPATH += $$PWD/../../../ROADcodec/ROADcoder/ROADoverCoder

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../EncodingOptions/release/ -lEncodingOptions
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../EncodingOptions/debug/ -lEncodingOptions
else:unix: LIBS += -L$$OUT_PWD/../../../Bin/ROADConverter/ -lEncodingOptions

INCLUDEPATH += $$PWD/../EncodingOptions
DEPENDPATH += $$PWD/../EncodingOptions
