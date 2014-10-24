#-------------------------------------------------
#
# Project created by QtCreator 2014-10-09T12:47:16
#
#-------------------------------------------------

QT       += widgets

TARGET = ListItemsModel
TEMPLATE = lib
CONFIG += c++11

DLLDESTDIR = ../../../Bin/ROADConverter

DEFINES += LISTITEMSMODEL_LIBRARY

SOURCES += listitemsmodel.cpp \
    modeloptions.cpp

HEADERS += listitemsmodel.h\
        listitemsmodel_global.h \
    modeloptions.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

FORMS += \
    listitem.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../ListItem/release/ -lListItem
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../ListItem/debug/ -lListItem
else:unix: LIBS += -L$$OUT_PWD/../ListItem/ -lListItem

INCLUDEPATH += $$PWD/../ListItem
DEPENDPATH += $$PWD/../ListItem
