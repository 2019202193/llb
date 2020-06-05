

QT += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TEMPLATE = app
CONFIG += console c++11
CONFIG += app_bundle
CONFIG += qt

SOURCES += \
        Pea.cpp \
        Sunflower.cpp \
        game.cpp \
        main.cpp \
        mainwindow.cpp \
        position.cpp \
        pushbutton.cpp \
        way.cpp \
        zom.cpp

FORMS += \
    mainwindow.ui

HEADERS += \
    Pea.h \
    Sunflower.h \
    game.h \
    mainwindow.h \
    position.h \
    pushbutton.h \
    way.h \
    zom.h

RESOURCES += \
    llb.qrc

DISTFILES +=
