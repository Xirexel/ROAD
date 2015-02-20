#-------------------------------------------------
#
# Project created by QtCreator 2014-10-09T12:47:16
#
#-------------------------------------------------

QT       += widgets

TARGET = ListItemsModel
TEMPLATE = lib
CONFIG += c++11

win32:DLLDESTDIR = ../../../Bin/ROADConverter
else:unix:DESTDIR = ../../../Bin/ROADConverter

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
else:unix: LIBS += -L$$OUT_PWD/../../../Bin/ROADConverter/ -lListItem

INCLUDEPATH += $$PWD/../ListItem
DEPENDPATH += $$PWD/../ListItem

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../../ROADcodec/PlatformDependencies/release/ -lPlatformDependencies
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../../ROADcodec/PlatformDependencies/debug/ -lPlatformDependencies
else:unix: LIBS += -L$$OUT_PWD/../../../ROADcodec/PlatformDependencies/ -lPlatformDependencies

INCLUDEPATH += $$PWD/../../../ROADcodec/PlatformDependencies
DEPENDPATH += $$PWD/../../../ROADcodec/PlatformDependencies

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../ROADcodec/PlatformDependencies/release/libPlatformDependencies.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../ROADcodec/PlatformDependencies/debug/libPlatformDependencies.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../ROADcodec/PlatformDependencies/release/PlatformDependencies.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../ROADcodec/PlatformDependencies/debug/PlatformDependencies.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../../ROADcodec/PlatformDependencies/libPlatformDependencies.a
