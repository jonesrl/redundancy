#-------------------------------------------------
#
# Project created by QtCreator 2012-03-11T09:21:12
#
#-------------------------------------------------

QT       -= core gui
include(../redundancy.pri)
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = logic
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    ifilesystemobject.cc \
    iscantarget.cc \
    ifilescantarget.cc \
    filescantarget.cc \
    file.cc \
    ifile.cc \
    idirectory.cc \
    directory.cc

HEADERS += \
    ifilesystemobject.h \
    iscantarget.h \
    ifilescantarget.h \
    filescantarget.h \
    file.h \
    ifile.h \
    idirectory.h \
    directory.h
unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}



unix:!macx: LIBS += -lboost_system

unix:!macx: LIBS += -lboost_filesystem
