#-------------------------------------------------
#
# Project created by QtCreator 2014-10-09T21:26:23
#
#-------------------------------------------------

QT       += widgets multimedia

TARGET = ListItem
TEMPLATE = lib
CONFIG += c++11

win32:DLLDESTDIR = ../../../Bin/ROADConverter
else:unix:DESTDIR = ../../../Bin/ROADConverter

DEFINES += LISTITEM_LIBRARY

SOURCES += \
    listitem.cpp \
    progresscontrolpanel.cpp \
    encodingthread.cpp \
    optionswidget.cpp

HEADERS +=\
        listitem_global.h \
    listitem.h \
    progresscontrolpanel.h \
    interfaces.h \
    encodingthread.h \
    optionswidget.h


FORMS += \
    listitem.ui \
    progresscontrolpanel.ui \
    optionswidget.ui

RESOURCES += \
    Resources/Resource.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../AudioFormatReader/release/ -lAudioFormatReader
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../AudioFormatReader/debug/ -lAudioFormatReader
else:unix: LIBS += -L$$OUT_PWD/../../../Bin/ROADConverter/ -lAudioFormatReader

INCLUDEPATH += $$PWD/../AudioFormatReader
DEPENDPATH += $$PWD/../AudioFormatReader

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../EncodingOptions/release/ -lEncodingOptions
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../EncodingOptions/debug/ -lEncodingOptions
else:unix: LIBS += -L$$OUT_PWD/../../../Bin/ROADConverter/ -lEncodingOptions

INCLUDEPATH += $$PWD/../EncodingOptions
DEPENDPATH += $$PWD/../EncodingOptions

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../EncodingOptionsWidgetFactory/release/ -lEncodingOptionsWidgetFactory
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../EncodingOptionsWidgetFactory/debug/ -lEncodingOptionsWidgetFactory
else:unix: LIBS += -L$$OUT_PWD/../../../Bin/ROADConverter/ -lEncodingOptionsWidgetFactory

INCLUDEPATH += $$PWD/../EncodingOptionsWidgetFactory
DEPENDPATH += $$PWD/../EncodingOptionsWidgetFactory
