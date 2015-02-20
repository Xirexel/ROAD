#-------------------------------------------------
#
# Project created by QtCreator 2014-12-30T23:47:23
#
#-------------------------------------------------

QT       += widgets

TARGET = EncodingOptionsWidgetFactory
TEMPLATE = lib
CONFIG += c++11

win32:DLLDESTDIR = ../../../Bin/ROADConverter
else:unix:DESTDIR = ../../../Bin/ROADConverter

DEFINES += ENCODINGOPTIONSWIDGETFACTORY_LIBRARY

SOURCES += encodingoptionswidgetfactory.cpp \
    encodingoptionsexperementalwidget.cpp \
    encodingoptionswidget.cpp \
    encodingoptionsfirstversionwidget.cpp

HEADERS += encodingoptionswidgetfactory.h\
        encodingoptionswidgetfactory_global.h \
    encodingoptionsexperementalwidget.h \
    encodingoptionswidget.h \
    encodingoptionsfirstversionwidget.h


FORMS += \
    encodingoptionsexperementalwidget.ui \
    encodingoptionsfirstversionwidget.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../../ROADcodec/ROADcoder/ROADoverCoder/release/ -lROADoverCoder
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../../ROADcodec/ROADcoder/ROADoverCoder/debug/ -lROADoverCoder
else:unix: LIBS += -L$$OUT_PWD/../../../Bin/ROADcoder/ -lROADoverCoder

INCLUDEPATH += $$PWD/../../../ROADcodec/ROADcoder/ROADoverCoder
DEPENDPATH += $$PWD/../../../ROADcodec/ROADcoder/ROADoverCoder

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../EncodingOptions/release/ -lEncodingOptions
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../EncodingOptions/debug/ -lEncodingOptions
else:unix: LIBS += -L$$OUT_PWD/../../../Bin/ROADConverter/ -lEncodingOptions

INCLUDEPATH += $$PWD/../EncodingOptions
DEPENDPATH += $$PWD/../EncodingOptions

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
