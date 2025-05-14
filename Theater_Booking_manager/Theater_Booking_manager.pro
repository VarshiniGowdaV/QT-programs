TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle

SOURCES += \
        calender.cpp \
        date.cpp \
        main.cpp \
        mainwindow.cpp \
        month.cpp \
        theater.cpp \
        theatermanager.cpp \
        year.cpp

HEADERS += \
    calender.h \
    date.h \
    mainwindow.h \
    month.h \
    theater.h \
    theatermanager.h \
    year.h

QT += widgets
