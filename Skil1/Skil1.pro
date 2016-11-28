QT += core
QT -= gui

CONFIG += c++11

TARGET = Skil1
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    person.cpp \
    personmanager.cpp \
    console.cpp

HEADERS += \
    person.h \
    personmanager.h \
    console.h

DISTFILES += \
    persons.txt
