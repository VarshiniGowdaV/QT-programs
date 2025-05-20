TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG += qt

SOURCES += \
        BatteryManager.cpp \
        SoundManager.cpp \
        main.cpp

HEADERS += \
    BatteryManager.h \
    SoundManager.h


QT += widgets core
