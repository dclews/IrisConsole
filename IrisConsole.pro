#-------------------------------------------------
#
# Project created by QtCreator 2014-02-25T22:08:27
#
#-------------------------------------------------

include(/usr/local/share/iris/iris_common.pri)

LIBS += -lIris

QT       -= gui

TARGET = IRCBot
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

HEADERS += <iris/iris.hpp>

unix {
    target.path = /usr/local/bin/
    INSTALLS += target
}
