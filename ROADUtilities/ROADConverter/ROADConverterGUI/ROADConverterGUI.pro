#-------------------------------------------------
#
# Project created by QtCreator 2014-10-09T12:19:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ROADConverterGUI
TEMPLATE = app
CONFIG += c++11

win32:DESTDIR = ../../../Bin/ROADConverter
else:unix{
DESTDIR = ../../../Bin/ROADConverter

DISTFILES += ../../../Bin/ROADcoder/libROADCoder.so
}

SOURCES += main.cpp\
        mainwidget.cpp \
    optionswidget.cpp

HEADERS  += mainwidget.h \
    optionswidget.h

FORMS    += mainwidget.ui \
    optionswidget.ui



win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../../ROADcodec/ROADcoder/ROADoverCoder/release/ -lROADoverCoder
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../../ROADcodec/ROADcoder/ROADoverCoder/debug/ -lROADoverCoder
else:unix: LIBS += -L$$OUT_PWD/../../../Bin/ROADcoder/ -lROADCoder

INCLUDEPATH += $$PWD/../../../ROADcodec/ROADcoder/ROADCoder
DEPENDPATH += $$PWD/../../../ROADcodec/ROADcoder/ROADCoder

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../../ROADcodec/ROADcoder/ROADoverCoder/release/ -lROADoverCoder
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../../ROADcodec/ROADcoder/ROADoverCoder/debug/ -lROADoverCoder
else:unix: LIBS += -L$$OUT_PWD/../../../Bin/ROADcoder/ -lROADoverCoder

INCLUDEPATH += $$PWD/../../../ROADcodec/ROADcoder/ROADoverCoder
DEPENDPATH += $$PWD/../../../ROADcodec/ROADcoder/ROADoverCoder

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../ListItemsModel/release/ -lListItemsModel
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../ListItemsModel/debug/ -lListItemsModel
else:unix: LIBS += -L$$OUT_PWD/../../../Bin/ROADConverter/ -lListItemsModel

INCLUDEPATH += $$PWD/../ListItemsModel
DEPENDPATH += $$PWD/../ListItemsModel

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../ListItem/release/ -lListItem
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../ListItem/debug/ -lListItem
else:unix: LIBS += -L$$OUT_PWD/../../../Bin/ROADConverter/ -lListItem

INCLUDEPATH += $$PWD/../ListItem
DEPENDPATH += $$PWD/../ListItem

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../EncodingOptions/release/ -lEncodingOptions
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../EncodingOptions/debug/ -lEncodingOptions
else:unix: LIBS += -L$$OUT_PWD/../../../Bin/ROADConverter/ -lEncodingOptions

INCLUDEPATH += $$PWD/../EncodingOptions
DEPENDPATH += $$PWD/../EncodingOptions

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../EncodingOptionsWidgetFactory/release/ -lEncodingOptionsWidgetFactory
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../EncodingOptionsWidgetFactory/debug/ -lEncodingOptionsWidgetFactory
else:unix: LIBS += -L$$OUT_PWD/../../../Bin/ROADConverter/ -lEncodingOptionsWidgetFactory

INCLUDEPATH += $$PWD/../EncodingOptionsWidgetFactory
DEPENDPATH += $$PWD/../EncodingOptionsWidgetFactory

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../AudioFormatReader/release/ -lAudioFormatReader
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../AudioFormatReader/debug/ -lAudioFormatReader
else:unix: LIBS += -L$$OUT_PWD/../../../Bin/ROADConverter/ -lAudioFormatReader

INCLUDEPATH += $$PWD/../AudioFormatReader
DEPENDPATH += $$PWD/../AudioFormatReader
