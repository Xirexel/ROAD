#-------------------------------------------------
#
# Project created by QtCreator 2015-01-25T22:40:14
#
#-------------------------------------------------

QT       -= core gui

TARGET = Driver
TEMPLATE = lib
CONFIG += staticlib
CONFIG += c++11

SOURCES += \
    DataDriver.cpp \
    DataWriteDriver.cpp

HEADERS += \
    DataDriver.h \
    DataWriteDriver.h \
    IDataWriteDriver.h

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
