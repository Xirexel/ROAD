#-------------------------------------------------
#
# Project created by QtCreator 2014-09-13T01:46:51
#
#-------------------------------------------------

QT       += widgets

TARGET = Audio_Fractal_Encoder_Widget
TEMPLATE = lib
CONFIG += c++11


DLLDESTDIR = ../Bin


DEFINES += AUDIO_FRACTAL_ENCODER_WIDGET_LIBRARY AUDIO_FRACTAL_ENCODER_LIBRARY_LIBRARY

SOURCES += \
    audiofractalencoderwidget.cpp \
    progressprocessingwidget.cpp \
    processingthread.cpp \
    wave_parser.cpp \
    iwavereader.cpp \
    iwavefractalwriter.cpp

HEADERS +=\
        audio_fractal_encoder_widget_global.h \
    audiofractalencoderwidget.h \
    progressprocessingwidget.h \
    processingthread.h \
    wave_parser.h \
    iwavereader.h \
    wavereader.h \
    iwavefractalwriter.h \
    wavefractalwriter.h \
    fractalchanks.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

FORMS += \
    audiofractalencoderwidget.ui \
    progressprocessingwidget.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Audio_Fractal_Encoder_Library/release/ -lAudio_Fractal_Encoder_Library
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Audio_Fractal_Encoder_Library/debug/ -lAudio_Fractal_Encoder_Library
else:unix: LIBS += -L$$OUT_PWD/../Audio_Fractal_Encoder_Library/ -lAudio_Fractal_Encoder_Library

INCLUDEPATH += $$PWD/../Audio_Fractal_Encoder_Library
DEPENDPATH += $$PWD/../Audio_Fractal_Encoder_Library

RESOURCES +=
