#-------------------------------------------------
#
# Project created by QtCreator 2014-09-13T02:59:19
#
#-------------------------------------------------

QT       -=  gui

TARGET = Audio_Fractal_Encoder_Library
TEMPLATE = lib
CONFIG += c++11




DLLDESTDIR = ../Bin




DEFINES += AUDIO_FRACTAL_ENCODER_LIBRARY_LIBRARY

SOURCES += \
    Audio_Fractal_Encoder.cpp \
    DataBuffer.cpp \
    Domain.cpp \
    DomainPool.cpp \
    DoubleDataContainer.cpp \
    FractalDataContainer.cpp \
    FractalEncoder.cpp \
    FractalEncodingOptions.cpp \
    FractalItem.cpp \
    FrameFractalItemCollection.cpp \
    IDomain.cpp \
    IDoubleDataContainer.cpp \
    IFractalDataContainer.cpp \
    IFractalItem.cpp \
    IFrameFractalItemCollection.cpp \
    IMixingChannels.cpp \
    IRawDataReader.cpp \
    IRawDataWriter.cpp \
    IUCharDataContainer.cpp \
    LminusRMixing.cpp \
    LplusRMixing.cpp \
    MixingChannelsMode.cpp \
    NoneMixing.cpp \
    ReadResult.cpp \
    SuperFrameFractalItemCollection.cpp \
    UCharDataContainer.cpp

HEADERS +=\
        audio_fractal_encoder_library_global.h \
    Audio_Fractal_Encoder.h \
    DataBuffer.h \
    Domain.h \
    DomainPool.h \
    DoubleDataContainer.h \
    FractalDataContainer.h \
    FractalEncoder.h \
    FractalEncodingOptions.h \
    FractalItem.h \
    FrameFractalItemCollection.h \
    IDomain.h \
    IDoubleDataContainer.h \
    IFractalDataContainer.h \
    IFractalItem.h \
    IFrameFractalItemCollection.h \
    IMixingChannels.h \
    IRawDataReader.h \
    IRawDataWriter.h \
    IUCharDataContainer.h \
    LminusRMixing.h \
    LplusRMixing.h \
    MixingChannelsMode.h \
    NoneMixing.h \
    ReadResult.h \
    SuperFrameFractalItemCollection.h \
    UCharDataContainer.h \
    LogPrintOut.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
