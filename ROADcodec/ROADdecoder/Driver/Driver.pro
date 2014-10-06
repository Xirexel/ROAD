#-------------------------------------------------
#
# Project created by QtCreator 2014-12-02T10:07:36
#
#-------------------------------------------------

QT       -= gui

TARGET = Driver
TEMPLATE = lib
CONFIG += staticlib
CONFIG += c++11


HEADERS += \
    DataDriver.h \
    DataReadDriver.h \
    IDataReadDriver.h

SOURCES += \
    DataDriver.cpp \
    DataReadDriver.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../Endian/release/ -lEndian
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../Endian/debug/ -lEndian
else:unix: LIBS += -L$$OUT_PWD/../../Endian/ -lEndian

INCLUDEPATH += $$PWD/../../Endian
DEPENDPATH += $$PWD/../../Endian

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Endian/release/libEndian.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Endian/debug/libEndian.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Endian/release/Endian.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Endian/debug/Endian.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../Endian/libEndian.a
