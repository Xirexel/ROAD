#-------------------------------------------------
#
# Project created by QtCreator 2014-12-18T23:01:50
#
#-------------------------------------------------

QT       -= gui

TARGET = ROADoverCoder
TEMPLATE = lib
CONFIG += c++11

win32:DLLDESTDIR = ../../../Bin/ROADcoder ../../../Bin/ROADConverter
else:unix:DESTDIR = ../../../Bin/ROADcoder

DEFINES += ROADOVERCODER_LIBRARY


unix {
    target.path = /usr/lib
    INSTALLS += target
}

HEADERS += \
    ChannelsMixingMode.h \
    DoubleDataContainer.h \
    FractalAverItem.h \
    FractalFirstOrderItem.h \
    FractalFirstOrderItemSuperFrameContainer.h \
    IChannelsMixing.h \
    IDoubleDataContainer.h \
    IRawDataBuffer.h \
    IROADoverEncodingOptions.h \
    IROADoverManager.h \
    MIDChannelsMixing.h \
    NoneChannelsMixing.h \
    RawDataBuffer.h \
    Result.h \
    ROADFormatMode.h \
    ROADover.h \
    ROADoverEncodingOptionsExperemental.h \
    ROADoverManager.h \
    ROADoverManagerExperemental.h \
    SIDEChannelsMixing.h \
    FractalFirstOrderItemContainer.h \
    roadovercoder_global.h \
    ROADoverEncodingOptionsFactory.h \
    FractalFormatRawDataContainer.h \
    FractalEncodingOptions.h \
    ROADRawDataFormat.h

SOURCES += \
    DoubleDataContainer.cpp \
    FractalAverItem.cpp \
    FractalFirstOrderItem.cpp \
    FractalFirstOrderItemSuperFrameContainer.cpp \
    MIDChannelsMixing.cpp \
    NoneChannelsMixing.cpp \
    RawDataBuffer.cpp \
    ROADover.cpp \
    ROADoverEncodingOptionsExperemental.cpp \
    ROADoverManager.cpp \
    ROADoverManagerExperemental.cpp \
    SIDEChannelsMixing.cpp \
    FractalFirstOrderItemContainer.cpp \
    ROADoverEncodingOptionsFactory.cpp \
    FractalFormatRawDataContainer.cpp \
    FractalEncodingOptions.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../ROADCoder/release/ -lROADCoder
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../ROADCoder/debug/ -lROADCoder
else:unix: LIBS += -L$$OUT_PWD/../../../Bin/ROADcoder/ -lROADCoder

INCLUDEPATH += $$PWD/../ROADCoder
DEPENDPATH += $$PWD/../ROADCoder
