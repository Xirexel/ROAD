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
        mainwidget.cpp

HEADERS  += mainwidget.h

FORMS    += mainwidget.ui



win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../AudioPlayer/release/ -lAudioPlayer
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../AudioPlayer/debug/ -lAudioPlayer
else:unix: LIBS += -L$$OUT_PWD/../AudioPlayer/ -lAudioPlayer

INCLUDEPATH += $$PWD/../AudioPlayer
DEPENDPATH += $$PWD/../AudioPlayer

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../AudioPlayer/release/libAudioPlayer.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../AudioPlayer/debug/libAudioPlayer.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../AudioPlayer/release/AudioPlayer.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../AudioPlayer/debug/AudioPlayer.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../AudioPlayer/libAudioPlayer.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../ROADoverWAVE/release/ -lROADoverWAVE
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../ROADoverWAVE/debug/ -lROADoverWAVE
else:unix: LIBS += -L$$OUT_PWD/../ROADoverWAVE/ -lROADoverWAVE

INCLUDEPATH += $$PWD/../ROADoverWAVE
DEPENDPATH += $$PWD/../ROADoverWAVE

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../ROADoverWAVE/release/libROADoverWAVE.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../ROADoverWAVE/debug/libROADoverWAVE.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../ROADoverWAVE/release/ROADoverWAVE.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../ROADoverWAVE/debug/ROADoverWAVE.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../ROADoverWAVE/libROADoverWAVE.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../../ROADcodec/ROADdecoder/ROADover/release/ -lROADover
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../../ROADcodec/ROADdecoder/ROADover/debug/ -lROADover
else:unix: LIBS += -L$$OUT_PWD/../../../ROADcodec/ROADdecoder/ROADover/ -lROADover

INCLUDEPATH += $$PWD/../../../ROADcodec/ROADdecoder/ROADover
DEPENDPATH += $$PWD/../../../ROADcodec/ROADdecoder/ROADover

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../../ROADcodec/Driver/release/ -lDriver
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../../ROADcodec/Driver/debug/ -lDriver
else:unix: LIBS += -L$$OUT_PWD/../../../ROADcodec/Driver/ -lDriver

INCLUDEPATH += $$PWD/../../../ROADcodec/Driver
DEPENDPATH += $$PWD/../../../ROADcodec/Driver
