#-------------------------------------------------
#
# Project created by QtCreator 2012-03-11T09:21:12
#
#-------------------------------------------------

QT       -= core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = logic
TEMPLATE = lib
CONFIG += staticlib

SOURCES +=

HEADERS += \
    ifilesystemobject.h
unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../usr/lib/release/ -lboost_filesystem
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../usr/lib/debug/ -lboost_filesystem
else:symbian: LIBS += -lboost_filesystem
else:unix: LIBS += -L$$PWD/../../../../usr/lib/ -lboost_filesystem

INCLUDEPATH += $$PWD/../../../../usr/include/boost
DEPENDPATH += $$PWD/../../../../usr/include/boost

unix|win32: LIBS += -lboost_system
