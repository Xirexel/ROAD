#-------------------------------------------------
#
# Project created by QtCreator 2014-11-05T11:52:47
#
#-------------------------------------------------

QT       -= gui

TARGET = ROAD
TEMPLATE = lib
CONFIG += c++11

win32:DLLDESTDIR = ../../../Bin/ROADdecoder ../../../Bin/ROADPlayer
else:unix:DESTDIR = ../../../Bin/ROADdecoder

DEFINES += ROAD_LIBRARY

SOURCES += \
    ROADFractalBuilderNoneFixedRangLength.cpp \
    ROADFractalFirstOrderBuilderFactory.cpp \
    DomainProcessorFirstOrderNoneFixedLength.cpp \
    ROADFractalOrderFactory.cpp

HEADERS +=\
    IFractalAverItem.h \
    ROADFractalFirstOrderBuilderFactory.h \
    ROADFractalFirstOrderBuilderNoneFixedRangLength.h \
    IROADFractalFirstOrderBuilder.h \
    IFractalFirstOrderItemContainer.h \
    IFractalFirstOrderItem.h \
    DomainProcessorFirstOrderNoneFixedLength.h \
    IROADFractalBuilderFactory.h \
    ROADFractalOrderFactory.h \
    ROADFractalFirstOrderBuilderTemplate.h

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../PlatformDependencies/release/ -lPlatformDependencies
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../PlatformDependencies/debug/ -lPlatformDependencies
else:unix: LIBS += -L$$OUT_PWD/../../PlatformDependencies/ -lPlatformDependencies

INCLUDEPATH += $$PWD/../../PlatformDependencies
DEPENDPATH += $$PWD/../../PlatformDependencies

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../PlatformDependencies/release/libPlatformDependencies.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../PlatformDependencies/debug/libPlatformDependencies.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../PlatformDependencies/release/PlatformDependencies.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../PlatformDependencies/debug/PlatformDependencies.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../PlatformDependencies/libPlatformDependencies.a
