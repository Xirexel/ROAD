#-------------------------------------------------
#
# Project created by QtCreator 2014-09-14T17:30:06
#
#-------------------------------------------------

QT       += widgets multimedia

TARGET = Audio_Fractal_Decoder_Widget
TEMPLATE = lib
CONFIG += c++11

DLLDESTDIR = ../Bin


DEFINES += AUDIO_FRACTAL_DECODER_WIDGET_LIBRARY AUDIO_FRACTAL_DECODER_LIBRARY_LIBRARY

SOURCES += \
    audiofractaldecoderwidget.cpp \
    wavefractal_parser.cpp \
    wave_parser.cpp \
    audiowavefractalplayer.cpp \
    wavefractalreader.cpp \
    fractaltowaveconverter.cpp \
    decodingthread.cpp

HEADERS +=\
        audio_fractal_decoder_widget_global.h \
    audiofractaldecoderwidget.h \
    wavefractal_parser.h \
    wave_parser.h \
    audiowavefractalplayer.h \
    wavefractalreader.h \
    wavereader.h \
    IReader.h \
    fractalreader.h \
    fractaltowaveconverter.h \
    decodingthread.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

FORMS += \
    audiofractaldecoderwidget.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Audio_Fractal_Decoder_Library/release/ -lAudio_Fractal_Decoder_Library
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Audio_Fractal_Decoder_Library/debug/ -lAudio_Fractal_Decoder_Library
else:unix: LIBS += -L$$OUT_PWD/../Audio_Fractal_Decoder_Library/ -lAudio_Fractal_Decoder_Library

INCLUDEPATH += $$PWD/../Audio_Fractal_Decoder_Library
DEPENDPATH += $$PWD/../Audio_Fractal_Decoder_Library
