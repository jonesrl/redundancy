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


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../usr/lib/release/ -lboost_filesystem
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../usr/lib/debug/ -lboost_filesystem
else:symbian: LIBS += -lboost_filesystem
else:unix: LIBS += -L$$PWD/../../../../usr/lib/ -lboost_filesystem

INCLUDEPATH += $$PWD/../../../../usr/include/boost
DEPENDPATH += $$PWD/../../../../usr/include/boost



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../usr/lib/release/ -lboost_system
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../usr/lib/debug/ -lboost_system
else:symbian: LIBS += -lboost_system
else:unix: LIBS += -L$$PWD/../../../../usr/lib/ -lboost_system

INCLUDEPATH += $$PWD/../../../../usr/include
DEPENDPATH += $$PWD/../../../../usr/include

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../usr/lib/release/boost_system.lib
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../usr/lib/debug/boost_system.lib
else:unix:!symbian: PRE_TARGETDEPS += $$PWD/../../../../usr/lib/libboost_system.a
