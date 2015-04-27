#-------------------------------------------------
#
# Project created by QtCreator 2014-12-18T23:01:50
#
#-------------------------------------------------

QT       -= gui

TARGET = ROADoverCoder
TEMPLATE = lib
CONFIG += c++11

win32:DLLDESTDIR = ../../../Bin/ROADcoder ../../../Bin/ROADConverter
else:unix:DESTDIR = ../../../Bin/ROADcoder

DEFINES += ROADOVERCODER_LIBRARY


unix {
    target.path = /usr/lib
    INSTALLS += target
}

HEADERS += \
    ChannelsMixingMode.h \
    DoubleDataContainer.h \
    FractalAverItem.h \
    FractalFirstOrderItem.h \
    FractalFirstOrderItemSuperFrameContainer.h \
    IChannelsMixing.h \
    IDoubleDataContainer.h \
    IRawDataBuffer.h \
    IROADoverEncodingOptions.h \
    IROADoverManager.h \
    MIDChannelsMixing.h \
    NoneChannelsMixing.h \
    RawDataBuffer.h \
    Result.h \
    ROADFormatMode.h \
    ROADover.h \
    ROADoverEncodingOptionsExperemental.h \
    ROADoverManager.h \
    ROADoverManagerExperemental.h \
    SIDEChannelsMixing.h \
    FractalFirstOrderItemContainer.h \
    roadovercoder_global.h \
    ROADoverEncodingOptionsFactory.h \
    FractalFormatRawDataContainer.h \
    FractalEncodingOptions.h \
    ROADRawDataFormat.h \
    ROADoverEncodingOptionsFirstVersion.h \
    ROADoverManagerFirstVersion.h \
    ROADSeekPoint.h \
    ByteConvertor.h \
    IDecodedSampleTypeToRawDataSampleType.h \
    DecodedSampleTypeToRawDataSampleType.h \
    ROADoverCoderCommon.h

SOURCES += \
    DoubleDataContainer.cpp \
    FractalAverItem.cpp \
    FractalFirstOrderItem.cpp \
    FractalFirstOrderItemSuperFrameContainer.cpp \
    MIDChannelsMixing.cpp \
    NoneChannelsMixing.cpp \
    RawDataBuffer.cpp \
    ROADover.cpp \
    ROADoverEncodingOptionsExperemental.cpp \
    ROADoverManager.cpp \
    ROADoverManagerExperemental.cpp \
    SIDEChannelsMixing.cpp \
    FractalFirstOrderItemContainer.cpp \
    ROADoverEncodingOptionsFactory.cpp \
    FractalFormatRawDataContainer.cpp \
    FractalEncodingOptions.cpp \
    ROADoverEncodingOptionsFirstVersion.cpp \
    ROADoverManagerFirstVersion.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../ROADCoder/release/ -lROADCoder
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../ROADCoder/debug/ -lROADCoder
else:unix: LIBS += -L$$OUT_PWD/../../../Bin/ROADcoder/ -lROADCoder

INCLUDEPATH += $$PWD/../ROADCoder
DEPENDPATH += $$PWD/../ROADCoder

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../ROADdecoder/ROAD/release/ -lROAD
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../ROADdecoder/ROAD/debug/ -lROAD
else:unix: LIBS += -L$$OUT_PWD/../../ROADdecoder/ROAD/ -lROAD

INCLUDEPATH += $$PWD/../../ROADdecoder/ROAD
DEPENDPATH += $$PWD/../../ROADdecoder/ROAD

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
