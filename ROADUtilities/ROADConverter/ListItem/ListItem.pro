#-------------------------------------------------
#
# Project created by QtCreator 2014-10-09T21:26:23
#
#-------------------------------------------------

QT       += widgets multimedia

TARGET = ListItem
TEMPLATE = lib
CONFIG += c++11

DLLDESTDIR = ../../../Bin/ROADConverter

DEFINES += LISTITEM_LIBRARY

SOURCES += \
    listitem.cpp \
    progresscontrolpanel.cpp \
    encodingthread.cpp \
    roadovercoderoptions.cpp

HEADERS +=\
        listitem_global.h \
    listitem.h \
    progresscontrolpanel.h \
    interfaces.h \
    encodingthread.h \
    roadovercoderoptions.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

FORMS += \
    listitem.ui \
    progresscontrolpanel.ui

RESOURCES += \
    Resources/Resource.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../AudioFormatReader/release/ -lAudioFormatReader
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../AudioFormatReader/debug/ -lAudioFormatReader
else:unix: LIBS += -L$$OUT_PWD/../AudioFormatReader/ -lAudioFormatReader

INCLUDEPATH += $$PWD/../AudioFormatReader
DEPENDPATH += $$PWD/../AudioFormatReader
