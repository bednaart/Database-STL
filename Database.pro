TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS+=-std=c++11

SOURCES += main.cpp \
    cAddressBook.cpp \
    cContactCard.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    cAddressBook.h \
    cContactCard.h \
    main.h

