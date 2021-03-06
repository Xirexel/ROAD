#-------------------------------------------------
#
# Project created by QtCreator 2014-10-18T14:21:16
#
#-------------------------------------------------

QT       -=  gui

TARGET = ROADoverWAVE
TEMPLATE = lib
CONFIG += staticlib
CONFIG += c++11


DEFINES += ROADOVER_LIBRARY

SOURCES += \
    wavefractal_parser.cpp
HEADERS += roadoverwave.h \
    wavefractal_parser.h \
    roadoverwavedecryptorstub.h


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../../ROADcodec/ROADdecoder/ROADover/release/ -lROADover
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../../ROADcodec/ROADdecoder/ROADover/debug/ -lROADover
else:unix: LIBS += -L$$OUT_PWD/../../../ROADcodec/ROADdecoder/ROADover/ -lROADover

INCLUDEPATH += $$PWD/../../../ROADcodec/ROADdecoder/ROADover
DEPENDPATH += $$PWD/../../../ROADcodec/ROADdecoder/ROADover

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../../ROADcodec/ROADdecoder/Driver/release/ -lDriver
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../../ROADcodec/ROADdecoder/Driver/debug/ -lDriver
else:unix: LIBS += -L$$OUT_PWD/../../../ROADcodec/ROADdecoder/Driver/ -lDriver

INCLUDEPATH += $$PWD/../../../ROADcodec/ROADdecoder/Driver
DEPENDPATH += $$PWD/../../../ROADcodec/ROADdecoder/Driver

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../ROADcodec/ROADdecoder/Driver/release/libDriver.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../ROADcodec/ROADdecoder/Driver/debug/libDriver.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../ROADcodec/ROADdecoder/Driver/release/Driver.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../ROADcodec/ROADdecoder/Driver/debug/Driver.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../../ROADcodec/ROADdecoder/Driver/libDriver.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../../ROADcodec/Endian/release/ -lEndian
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../../ROADcodec/Endian/debug/ -lEndian
else:unix: LIBS += -L$$OUT_PWD/../../../ROADcodec/Endian/ -lEndian

INCLUDEPATH += $$PWD/../../../ROADcodec/Endian
DEPENDPATH += $$PWD/../../../ROADcodec/Endian

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../ROADcodec/Endian/release/libEndian.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../ROADcodec/Endian/debug/libEndian.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../ROADcodec/Endian/release/Endian.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../ROADcodec/Endian/debug/Endian.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../../ROADcodec/Endian/libEndian.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../../ROADcodec/PlatformDependencies/release/ -lPlatformDependencies
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../../ROADcodec/PlatformDependencies/debug/ -lPlatformDependencies
else:unix: LIBS += -L$$OUT_PWD/../../../ROADcodec/PlatformDependencies/ -lPlatformDependencies

INCLUDEPATH += $$PWD/../../../ROADcodec/PlatformDependencies
DEPENDPATH += $$PWD/../../../ROADcodec/PlatformDependencies

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../ROADcodec/PlatformDependencies/release/libPlatformDependencies.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../ROADcodec/PlatformDependencies/debug/libPlatformDependencies.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../ROADcodec/PlatformDependencies/release/PlatformDependencies.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../ROADcodec/PlatformDependencies/debug/PlatformDependencies.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../../ROADcodec/PlatformDependencies/libPlatformDependencies.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../../ROADcodec/CRC/release/ -lCRC
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../../ROADcodec/CRC/debug/ -lCRC
else:unix: LIBS += -L$$OUT_PWD/../../../ROADcodec/CRC/ -lCRC

INCLUDEPATH += $$PWD/../../../ROADcodec/CRC
DEPENDPATH += $$PWD/../../../ROADcodec/CRC

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../ROADcodec/CRC/release/libCRC.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../ROADcodec/CRC/debug/libCRC.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../ROADcodec/CRC/release/CRC.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../../ROADcodec/CRC/debug/CRC.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../../ROADcodec/CRC/libCRC.a
