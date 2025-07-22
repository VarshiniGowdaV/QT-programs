# QT += core
# CONFIG += console
# CONFIG -= app_bundle
# CONFIG += c++17

# SOURCES += main.cpp
# HEADERS += producer.h consumer.h

QT += core
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++17

TEMPLATE = app
TARGET = QTBUG-104863

SOURCES += main.cpp
HEADERS += producer.h \
           consumer.h
