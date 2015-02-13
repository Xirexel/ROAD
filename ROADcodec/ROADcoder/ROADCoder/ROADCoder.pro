#-------------------------------------------------
#
# Project created by QtCreator 2014-12-14T22:24:55
#
#-------------------------------------------------

QT       -= gui

TARGET = ROADCoder
TEMPLATE = lib
CONFIG += c++11

win32:DLLDESTDIR = ../../../Bin/ROADcoder ../../../Bin/ROADConverter
else:unix:DESTDIR = ../../../Bin/ROADcoder

DEFINES += ROADCODER_LIBRARY

SOURCES += \
    Domain.cpp \
    DomainPool.cpp \
    ROADOrderedFractalAnalyzerFactory.cpp \
    ROADFractalFirstOrderAnalyzerNoneFixedRangLength.cpp \
    ROADFractalFirstOrderAnalyzerFactory.cpp

HEADERS +=\
    Domain.h \
    DomainPool.h \
    IFractalAverItem.h \
    IFractalEncodingOptions.h \
    IROADFractalAnalyzerFactory.h \
    ROADOrderedFractalAnalyzerFactory.h \
    IFractalFirstOrderItem.h \
    IFractalFirstOrderItemContainer.h \
    IROADFractalFirstOrderAnalyzer.h \
    ROADFractalFirstOrderAnalyzerFactory.h \
    ROADFractalFirstOrderAnalyzerNoneFixedRangLength.h



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
