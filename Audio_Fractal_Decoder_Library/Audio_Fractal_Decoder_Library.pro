#-------------------------------------------------
#
# Project created by QtCreator 2014-09-15T12:40:38
#
#-------------------------------------------------

QT       -= gui

TARGET = Audio_Fractal_Decoder_Library
TEMPLATE = lib
CONFIG += c++11

DLLDESTDIR = ../Bin

DEFINES += AUDIO_FRACTAL_DECODER_LIBRARY_LIBRARY NON_DETERINETED_DECODING

SOURCES += \
    UIntDataContainer.cpp \
    UCharDataContainer.cpp \
    SuperFrameFractaItemCollection.cpp \
    ReadResult.cpp \
    NoneMixing.cpp \
    MixingChannelMode.cpp \
    LPlusRMixing.cpp \
    LMinusRMixing.cpp \
    IUIntDataContainer.cpp \
    IUCharDataContainer.cpp \
    IRawDataWriter.cpp \
    IRawDataReader.cpp \
    IMixing.cpp \
    IFractalItemContainer.cpp \
    IFractalItem.cpp \
    IFractalDataContainer.cpp \
    IDoubleDataContainer.cpp \
    FractalItemContainer.cpp \
    FractalItem.cpp \
    FractalDecodingOptions.cpp \
    FractalDecoder.cpp \
    FractalDataContainer.cpp \
    DoubleDataContainer.cpp \
    DomainProcessor.cpp \
    DataBuffer.cpp \
    Audio_Fractal_Decoder.cpp

HEADERS +=\
        audio_fractal_decoder_library_global.h \
    UIntDataContainer.h \
    UCharDataContainer.h \
    SuperFrameFractaItemCollection.h \
    ReadResult.h \
    NoneMixing.h \
    MixingChannelMode.h \
    LPlusRMixing.h \
    LMinusRMixing.h \
    IUIntDataContainer.h \
    IUCharDataContainer.h \
    IRawDataWriter.h \
    IRawDataReader.h \
    IMixing.h \
    IFractalItemContainer.h \
    IFractalItem.h \
    IFractalDataContainer.h \
    IDoubleDataContainer.h \
    FractalItemContainer.h \
    FractalItem.h \
    FractalDecodingOptions.h \
    FractalDecoder.h \
    FractalDataContainer.h \
    DoubleDataContainer.h \
    DomainProcessor.h \
    DataBuffer.h \
    Audio_Fractal_Decoder.h \
    LogPrintOut.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
