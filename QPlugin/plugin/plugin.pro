#-------------------------------------------------
#
# Project created by QtCreator 2017-10-17T14:15:43
#
#-------------------------------------------------

QT       -= gui

TARGET = personPlugin
TEMPLATE = lib
CONFIG += plugin


DEFINES += PLUGIN_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        programmer.cpp

HEADERS += \
        programmer.h \
        person.h


win32 {
    CONFIG(debug, release|debug):DESTDIR = ../debug/plugins/
    CONFIG(release, release|debug):DESTDIR = ../release/plugins/
} else {
    DESTDIR = ../plugins/
}

OTHER_FILES += \
    programmer.json
