#-------------------------------------------------
#
# Project created by QtCreator 2014-10-09T12:19:47
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ROADConverterGUI
TEMPLATE = app

DESTDIR = ../../Bin

SOURCES += main.cpp\
        mainwidget.cpp \
    optionswidget.cpp

HEADERS  += mainwidget.h \
    optionswidget.h

FORMS    += mainwidget.ui \
    optionswidget.ui

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../ListItemsModel/release/ -lListItemsModel
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../ListItemsModel/debug/ -lListItemsModel
else:unix: LIBS += -L$$OUT_PWD/../ListItemsModel/ -lListItemsModel

INCLUDEPATH += $$PWD/../ListItemsModel
DEPENDPATH += $$PWD/../ListItemsModel
