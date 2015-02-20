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

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../PlatformDependencies/release/ -lPlatformDependencies
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../PlatformDependencies/debug/ -lPlatformDependencies
else:unix: LIBS += -L$$OUT_PWD/../PlatformDependencies/ -lPlatformDependencies

INCLUDEPATH += $$PWD/../PlatformDependencies
DEPENDPATH += $$PWD/../PlatformDependencies

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../PlatformDependencies/release/libPlatformDependencies.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../PlatformDependencies/debug/libPlatformDependencies.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../PlatformDependencies/release/PlatformDependencies.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../PlatformDependencies/debug/PlatformDependencies.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../PlatformDependencies/libPlatformDependencies.a
