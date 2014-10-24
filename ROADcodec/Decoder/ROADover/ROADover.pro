#-------------------------------------------------
#
# Project created by QtCreator 2014-10-16T09:32:48
#
#-------------------------------------------------

QT       -= gui

TARGET = ROADover
TEMPLATE = lib
CONFIG += c++11

DLLDESTDIR = ../../../Bin/ROAD/Decoder

DEFINES += ROADOVER_LIBRARY

SOURCES += \
    AROADover.cpp \
    DoubleContainer.cpp \
    DoubleDataContainer.cpp \
    FractalDataContainer.cpp \
    FractalDataContainerCollection.cpp \
    IChannelsMixing.cpp \
    IFractalDataContainerCollection.cpp \
    LminusRMixingChannels.cpp \
    LplusRMixingChannels.cpp \
    MixingChannelsMode.cpp \
    NoneMixingChannels.cpp \
    RawDataBuffer.cpp \
    ROADdataBuffer.cpp \
    ROADFormat.cpp \
    ROADManager.cpp \
    ROADoverDecodingOptions.cpp \
    UCharDataContainer.cpp \
    UIntDataContainer.cpp

HEADERS +=\
        roadover_global.h \
    AROADover.h \
    DoubleContainer.h \
    DoubleDataContainer.h \
    FractalDataContainer.h \
    FractalDataContainerCollection.h \
    IChannelsMixing.h \
    IFractalDataContainerCollection.h \
    LminusRMixingChannels.h \
    LplusRMixingChannels.h \
    MixingChannelsMode.h \
    NoneMixingChannels.h \
    RawDataBuffer.h \
    ROADdataBuffer.h \
    ROADFormat.h \
    ROADManager.h \
    ROADoverDecodingOptions.h \
    UCharDataContainer.h \
    UIntDataContainer.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../ROAD/release/ -lROAD
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../ROAD/debug/ -lROAD
else:unix: LIBS += -L$$OUT_PWD/../ROAD/ -lROAD

INCLUDEPATH += $$PWD/../ROAD
DEPENDPATH += $$PWD/../ROAD
