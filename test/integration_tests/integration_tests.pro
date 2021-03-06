# XXX TODO: figure out how, if the target is built successfully, to run the setup.sh script,
#           then run the target, and then, if the target exits successfully, run the cleanup script
#           The QMAKE_POST_LINK only executes if the target is rebuilt
#           See http://qt-project.org/doc/qt-4.8/qmake-environment-reference.html
#           Until then, I just created a custom 'run target' in qtcreator

TEMPLATE = app
TARGET=integration_tests
include(../../redundancy.pri)
CONFIG += console
CONFIG -= qt

SOURCES += \
    integrationtestsrunner.cc \
    testfile.cc \
    testfilescantarget.cc \
    testdirectory.cc

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../logic/release/ -llogic
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../logic/debug/ -llogic
else:symbian: LIBS += -llogic
else:unix: LIBS += -L$$OUT_PWD/../../logic/ -llogic

INCLUDEPATH += $$PWD/../../logic
DEPENDPATH += $$PWD/../../logic

win32:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../logic/release/logic.lib
else:win32:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../logic/debug/logic.lib
else:unix:!symbian: PRE_TARGETDEPS += $$OUT_PWD/../../logic/liblogic.a

OTHER_FILES += \
    setup.sh \
    cleanup.sh \
    runintegrationtests.sh

INCLUDEPATH += /usr/include
DEPENDPATH += /usr/include
unix|win32: LIBS += -lboost_system
unix|win32: LIBS += -lboost_unit_test_framework
unix|win32: LIBS += -lboost_filesystem
