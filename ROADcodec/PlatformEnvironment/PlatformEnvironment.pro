#-------------------------------------------------
#
# Project created by QtCreator 2015-02-09T00:55:30
#
#-------------------------------------------------

QT       -= core gui

TARGET = PlatformEnvironment
TEMPLATE = lib
CONFIG += staticlib
CONFIG += c++11

SOURCES +=

HEADERS += platformenvironment.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
