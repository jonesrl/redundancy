TEMPLATE = app
TARGET=unit_tests
include(../../redundancy.pri)
CONFIG += console
CONFIG -= qt

INCLUDEPATH += ../../Catch/include
SOURCES += \
    testfile.cc \
    unittestsrunner.cc


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../logic/release/ -llogic
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../logic/debug/ -llogic
else:symbian: LIBS += -llogic
else:unix: LIBS += -L$$OUT_PWD/../../logic/ -llogic

INCLUDEPATH += $$PWD/../../logic
DEPENDPATH += $$PWD/../../logic

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../logic/release/logic.lib
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../logic/debug/logic.lib
else:unix:!symbian: PRE_TARGETDEPS += $$OUT_PWD/../../logic/liblogic.a

unix|win32: LIBS += -lboost_system
