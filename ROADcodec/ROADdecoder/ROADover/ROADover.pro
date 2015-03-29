#-------------------------------------------------
#
# Project created by QtCreator 2014-11-05T11:53:07
#
#-------------------------------------------------

QT       -= gui

TARGET = ROADover
TEMPLATE = lib
CONFIG += c++11

win32:DLLDESTDIR = ../../../Bin/ROADdecoder ../../../Bin/ROADPlayer
else:unix:DESTDIR = ../../../Bin/ROADdecoder

DEFINES += ROADOVER_LIBRARY

SOURCES += \
    DoubleDataContainer.cpp \
    FractalAverItem.cpp \
    MIDChannelsMixing.cpp \
    NoneChannelsMixing.cpp \
    RawDataBuffer.cpp \
    ROADoverDecodingOptionsExperemental.cpp \
    ROADoverDecodingOptionsFactory.cpp \
    ROADoverManager.cpp \
    ROADoverManagerExperemental.cpp \
    SIDEChannelsMixing.cpp \
    ROADover.cpp \
    FractalFirstOrderItem.cpp \
    FractalFirstOrderItemContainer.cpp \
    FractalFirstOrderItemSuperFrameContainer.cpp \
    ROADoverDecodingOptionsFirstOrderVersion.cpp

HEADERS +=\
        roadover_global.h \
    ChannelsMixingMode.h \
    DoubleDataContainer.h \
    FractalAverItem.h \
    IChannelsMixing.h \
    IDoubleDataContainer.h \
    IRawDataBuffer.h \
    IROADoverDecodingOptions.h \
    IROADoverManager.h \
    MIDChannelsMixing.h \
    NoneChannelsMixing.h \
    RawDataBuffer.h \
    Result.h \
    ROADFormatMode.h \
    ROADoverDecodingOptionsExperemental.h \
    ROADoverDecodingOptionsFactory.h \
    ROADoverManager.h \
    ROADoverManagerExperemental.h \
    SIDEChannelsMixing.h \
    ROADover.h \
    FractalFirstOrderItem.h \
    FractalFirstOrderItemContainer.h \
    FractalFirstOrderItemSuperFrameContainer.h \
    ROADRawMetaDataContainer.h \
    ROADRawDataFormat.h \
    ROADoverDecodingOptionsFirstOrderVersion.h \
    IROADoverDecodingOptionsMainVersion.h



win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../ROAD/release/ -lROAD
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../ROAD/debug/ -lROAD
else:unix: LIBS += -L$$OUT_PWD/../../../Bin/ROADdecoder/ -lROAD

INCLUDEPATH += $$PWD/../ROAD
DEPENDPATH += $$PWD/../ROAD

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Driver/release/ -lDriver
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Driver/debug/ -lDriver
else:unix: LIBS += -L$$OUT_PWD/../Driver/ -lDriver

INCLUDEPATH += $$PWD/../Driver
DEPENDPATH += $$PWD/../Driver

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Driver/release/libDriver.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Driver/debug/libDriver.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Driver/release/Driver.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../Driver/debug/Driver.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../Driver/libDriver.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../PlatformDependencies/release/ -lPlatformDependencies
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../PlatformDependencies/debug/ -lPlatformDependencies
else:unix: LIBS += -L$$OUT_PWD/../../PlatformDependencies/ -lPlatformDependencies

INCLUDEPATH += $$PWD/../../PlatformDependencies
DEPENDPATH += $$PWD/../../PlatformDependencies

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../PlatformDependencies/release/libPlatformDependencies.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../PlatformDependencies/debug/libPlatformDependencies.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../PlatformDependencies/release/PlatformDependencies.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../PlatformDependencies/debug/PlatformDependencies.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../PlatformDependencies/libPlatformDependencies.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../Endian/release/ -lEndian
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../Endian/debug/ -lEndian
else:unix: LIBS += -L$$OUT_PWD/../../Endian/ -lEndian

INCLUDEPATH += $$PWD/../../Endian
DEPENDPATH += $$PWD/../../Endian

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Endian/release/libEndian.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Endian/debug/libEndian.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Endian/release/Endian.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../Endian/debug/Endian.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../Endian/libEndian.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../CRC/release/ -lCRC
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../CRC/debug/ -lCRC
else:unix: LIBS += -L$$OUT_PWD/../../CRC/ -lCRC

INCLUDEPATH += $$PWD/../../CRC
DEPENDPATH += $$PWD/../../CRC

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../CRC/release/libCRC.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../CRC/debug/libCRC.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../CRC/release/CRC.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../CRC/debug/CRC.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../CRC/libCRC.a
