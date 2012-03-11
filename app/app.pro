TEMPLATE = app
TARGET=redundancy
CONFIG += console
CONFIG -= qt

SOURCES += main.cpp


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../logic/release/ -llogic
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../logic/debug/ -llogic
else:symbian: LIBS += -llogic
else:unix: LIBS += -L$$OUT_PWD/../logic/ -llogic

INCLUDEPATH += $$PWD/../logic
DEPENDPATH += $$PWD/../logic

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../logic/release/logic.lib
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../logic/debug/logic.lib
else:unix:!symbian: PRE_TARGETDEPS += $$OUT_PWD/../logic/liblogic.a
