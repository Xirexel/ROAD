#-------------------------------------------------
#
# Project created by QtCreator 2014-10-13T10:21:23
#
#-------------------------------------------------

QT       += multimedia

QT       -= gui

TARGET = AudioFormatReader
TEMPLATE = lib
CONFIG += c++11

win32:DLLDESTDIR = ../../../Bin/ROADConverter
else:unix:DESTDIR = ../../../Bin/ROADConverter

DLLDESTDIR = ../../../Bin/ROADConverter

DEFINES += AUDIOFORMATREADER_LIBRARY

SOURCES += \
    ireaderfactory.cpp \
    wave_parser.cpp \
    originalaudiostreamoptions.cpp

HEADERS +=\
        audioformatreader_global.h \
    ireaderfactory.h \
    wave_parser.h \
    WaveReader.h \
    ireader.h \
    originalaudiostreamoptions.h


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
