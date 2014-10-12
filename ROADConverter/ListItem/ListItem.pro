#-------------------------------------------------
#
# Project created by QtCreator 2014-10-09T21:26:23
#
#-------------------------------------------------

QT       += widgets multimedia

TARGET = ListItem
TEMPLATE = lib
CONFIG += c++11

DLLDESTDIR = ../../Bin

DEFINES += LISTITEM_LIBRARY

SOURCES += \
    listitem.cpp \
    progresscontrolpanel.cpp \
    roadovercoderoptions.cpp

HEADERS +=\
        listitem_global.h \
    listitem.h \
    progresscontrolpanel.h \
    roadovercoderoptions.h \
    interfaces.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

FORMS += \
    listitem.ui \
    progresscontrolpanel.ui

RESOURCES += \
    Resources/Resource.qrc
