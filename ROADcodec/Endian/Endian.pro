#-------------------------------------------------
#
# Project created by QtCreator 2014-11-13T16:13:40
#
#-------------------------------------------------

QT       -= gui

TARGET = Endian
TEMPLATE = lib
CONFIG += staticlib
CONFIG += c++11

HEADERS +=\
    BigEndianConvertor.h \
    EndianConvertorFactory.h \
    EndianType.h \
    IEndianConvertor.h \
    LittleEndianConvertor.h \
    LocalEndianConvertor.h

SOURCES += \
    BigEndianConvertor.cpp \
    EndianConvertorFactory.cpp \
    LittleEndianConvertor.cpp \
    LocalEndianConvertor.cpp

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
