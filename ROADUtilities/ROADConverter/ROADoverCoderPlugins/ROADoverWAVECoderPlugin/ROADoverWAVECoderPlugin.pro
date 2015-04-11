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
    awavefractalwriter.cpp \
    roadovercoderfactory.cpp

HEADERS += roadoverwavecoder.h\
        roadoverwavecoder_global.h \
    roadoverwavecoderplugin.h \
    awavefractalwriter.h \
    fractalchanks.h \
    WaveFractalWriter.h \
    wave_chunks.h \
    roadovercoderfactory.h



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

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../../../ROADcodec/CRC/release/ -lCRC
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../../../ROADcodec/CRC/debug/ -lCRC
else:unix: LIBS += -L$$OUT_PWD/../../../../ROADcodec/CRC/ -lCRC

INCLUDEPATH += $$PWD/../../../../ROADcodec/CRC
DEPENDPATH += $$PWD/../../../../ROADcodec/CRC

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../../ROADcodec/CRC/release/libCRC.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../../ROADcodec/CRC/debug/libCRC.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../../ROADcodec/CRC/release/CRC.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../../ROADcodec/CRC/debug/CRC.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../../../ROADcodec/CRC/libCRC.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../../../ROADcodec/ROADcoder/Driver/release/ -lDriver
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../../../ROADcodec/ROADcoder/Driver/debug/ -lDriver
else:unix: LIBS += -L$$OUT_PWD/../../../../ROADcodec/ROADcoder/Driver/ -lDriver

INCLUDEPATH += $$PWD/../../../../ROADcodec/ROADcoder/Driver
DEPENDPATH += $$PWD/../../../../ROADcodec/ROADcoder/Driver

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../../ROADcodec/ROADcoder/Driver/release/libDriver.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../../ROADcodec/ROADcoder/Driver/debug/libDriver.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../../ROADcodec/ROADcoder/Driver/release/Driver.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../../ROADcodec/ROADcoder/Driver/debug/Driver.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../../../ROADcodec/ROADcoder/Driver/libDriver.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../../../ROADcodec/Endian/release/ -lEndian
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../../../ROADcodec/Endian/debug/ -lEndian
else:unix: LIBS += -L$$OUT_PWD/../../../../ROADcodec/Endian/ -lEndian

INCLUDEPATH += $$PWD/../../../../ROADcodec/Endian
DEPENDPATH += $$PWD/../../../../ROADcodec/Endian

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../../ROADcodec/Endian/release/libEndian.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../../ROADcodec/Endian/debug/libEndian.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../../ROADcodec/Endian/release/Endian.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../../ROADcodec/Endian/debug/Endian.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../../../ROADcodec/Endian/libEndian.a
