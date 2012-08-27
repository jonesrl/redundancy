TEMPLATE = subdirs
CONFIG += ordered

include($$PWD/redundancy.pri)
SUBDIRS += \
    logic \
    test \
    app
