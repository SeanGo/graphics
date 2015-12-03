TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += ../include/vecmath
LIBS += -lglut -lGL -lGLU -lm

SOURCES += main.cpp

DISTFILES += \
    MIT6_837F12_assn0.pdf \
    a0soln

