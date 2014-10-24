#-------------------------------------------------
#
# Project created by QtCreator 2014-10-18T14:21:42
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ROADPlayerGUI
TEMPLATE = app
CONFIG += c++11

DESTDIR = ../../../Bin/ROADPlayer

DEFINES += ROADOVER_LIBRARY


SOURCES += main.cpp\
        mainwidget.cpp \
    audioplayer.cpp \
    wavefractalreader.cpp

HEADERS  += mainwidget.h \
    audioplayer.h \
    wavefractalreader.h

FORMS    += mainwidget.ui



win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../ROADoverWAVE/release/ -lROADoverWAVE
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../ROADoverWAVE/debug/ -lROADoverWAVE
else:unix: LIBS += -L$$OUT_PWD/../ROADoverWAVE/ -lROADoverWAVE

INCLUDEPATH += $$PWD/../ROADoverWAVE
DEPENDPATH += $$PWD/../ROADoverWAVE

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../ROADoverWAVE/release/libROADoverWAVE.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../ROADoverWAVE/debug/libROADoverWAVE.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../ROADoverWAVE/release/ROADoverWAVE.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../ROADoverWAVE/debug/ROADoverWAVE.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../ROADoverWAVE/libROADoverWAVE.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../../ROADcodec/Decoder/ROADover/release/ -lROADover
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../../ROADcodec/Decoder/ROADover/debug/ -lROADover
else:unix: LIBS += -L$$OUT_PWD/../../../ROADcodec/Decoder/ROADover/ -lROADover

INCLUDEPATH += $$PWD/../../../ROADcodec/Decoder/ROADover
DEPENDPATH += $$PWD/../../../ROADcodec/Decoder/ROADover
