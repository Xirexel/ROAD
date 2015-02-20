#-------------------------------------------------
#
# Project created by QtCreator 2014-10-09T16:18:23
#
#-------------------------------------------------

QT       -= gui

TARGET = ROADoverWAVECoderPlugin
TEMPLATE = lib
CONFIG  += plugin
CONFIG += c++11



win32:DLLDESTDIR = ../../../../Bin/ROADConverter/Plugins/ROADoverCoderPlugins
else:unix:DESTDIR = ../../../../Bin/ROADConverter/Plugins/ROADoverCoderPlugins


DEFINES += ROADOVERWAVECODER_LIBRARY

SOURCES += roadoverwavecoder.cpp \
    roadoverwavecoderplugin.cpp \
    awavefractalwriter.cpp

HEADERS += roadoverwavecoder.h\
        roadoverwavecoder_global.h \
    roadoverwavecoderplugin.h \
    awavefractalwriter.h \
    fractalchanks.h \
    WaveFractalWriter.h \
    wave_chunks.h



win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../../../ROADcodec/ROADcoder/ROADoverCoder/release/ -lROADoverCoder
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../../../ROADcodec/ROADcoder/ROADoverCoder/debug/ -lROADoverCoder
else:unix: LIBS += -L$$OUT_PWD/../../../../Bin/ROADcoder/ -lROADoverCoder

INCLUDEPATH += $$PWD/../../../../ROADcodec/ROADcoder/ROADoverCoder
DEPENDPATH += $$PWD/../../../../ROADcodec/ROADcoder/ROADoverCoder

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../../../ROADcodec/ROADcoder/ROADCoder/release/ -lROADCoder
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../../../ROADcodec/ROADcoder/ROADCoder/debug/ -lROADCoder
else:unix: LIBS += -L$$OUT_PWD/../../../../Bin/ROADcoder/ -lROADCoder

INCLUDEPATH += $$PWD/../../../../ROADcodec/ROADcoder/ROADCoder
DEPENDPATH += $$PWD/../../../../ROADcodec/ROADcoder/ROADCoder

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../../../ROADcodec/PlatformDependencies/release/ -lPlatformDependencies
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../../../ROADcodec/PlatformDependencies/debug/ -lPlatformDependencies
else:unix: LIBS += -L$$OUT_PWD/../../../../ROADcodec/PlatformDependencies/ -lPlatformDependencies

INCLUDEPATH += $$PWD/../../../../ROADcodec/PlatformDependencies
DEPENDPATH += $$PWD/../../../../ROADcodec/PlatformDependencies

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../../ROADcodec/PlatformDependencies/release/libPlatformDependencies.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../../ROADcodec/PlatformDependencies/debug/libPlatformDependencies.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../../ROADcodec/PlatformDependencies/release/PlatformDependencies.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../../ROADcodec/PlatformDependencies/debug/PlatformDependencies.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../../../ROADcodec/PlatformDependencies/libPlatformDependencies.a
