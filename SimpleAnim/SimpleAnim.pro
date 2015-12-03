TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lglut -lGL -lGLU -lm

SOURCES += \
    SimpleAnim.c

HEADERS += \
    SimpleAnim.h

