#-------------------------------------------------
#
# Project created by QtCreator 2014-09-13T01:43:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Audio_Fractal_GUI
TEMPLATE = app


DESTDIR = ../Bin


SOURCES += main.cpp\
        mainwidget.cpp

HEADERS  += mainwidget.h

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Audio_Fractal_Encoder_Widget/release/ -lAudio_Fractal_Encoder_Widget
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Audio_Fractal_Encoder_Widget/debug/ -lAudio_Fractal_Encoder_Widget
else:unix: LIBS += -L$$OUT_PWD/../Audio_Fractal_Encoder_Widget/ -lAudio_Fractal_Encoder_Widget

INCLUDEPATH += $$PWD/../Audio_Fractal_Encoder_Widget
DEPENDPATH += $$PWD/../Audio_Fractal_Encoder_Widget

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Audio_Fractal_Decoder_Widget/release/ -lAudio_Fractal_Decoder_Widget
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Audio_Fractal_Decoder_Widget/debug/ -lAudio_Fractal_Decoder_Widget
else:unix: LIBS += -L$$OUT_PWD/../Audio_Fractal_Decoder_Widget/ -lAudio_Fractal_Decoder_Widget

INCLUDEPATH += $$PWD/../Audio_Fractal_Decoder_Widget
DEPENDPATH += $$PWD/../Audio_Fractal_Decoder_Widget
