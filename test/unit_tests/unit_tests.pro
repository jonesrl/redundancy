TEMPLATE = app
TARGET=unit_tests
include(../../redundancy.pri)
CONFIG += console
CONFIG -= qt


SOURCES += \
    testfile.cc \
    unittestsrunner.cc \
    testfilescantarget.cc \
    fakefile.cc


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../logic/release/ -llogic
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../logic/debug/ -llogic
else:symbian: LIBS += -llogic
else:unix: LIBS += -L$$OUT_PWD/../../logic/ -llogic

INCLUDEPATH += $$PWD/../../logic
DEPENDPATH += $$PWD/../../logic

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../logic/release/logic.lib
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../logic/debug/logic.lib
else:unix:!symbian: PRE_TARGETDEPS += $$OUT_PWD/../../logic/liblogic.a



unix|win32: LIBS += -lboost_filesystem

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../usr/lib/release/ -lboost_system
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../usr/lib/debug/ -lboost_system
else:symbian: LIBS += -lboost_system
else:unix: LIBS += -L$$PWD/../../../../../usr/lib/ -lboost_system

INCLUDEPATH += $$PWD/../../../../../usr/include
DEPENDPATH += $$PWD/../../../../../usr/include

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/lib/release/boost_system.lib
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../../usr/lib/debug/boost_system.lib
else:unix:!symbian: PRE_TARGETDEPS += $$PWD/../../../../../usr/lib/libboost_system.a



unix|win32: LIBS += -lboost_unit_test_framework

HEADERS += \
    fakefile.h
