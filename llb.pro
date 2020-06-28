


QT += core gui widgets
QT += core gui multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TEMPLATE = app
CONFIG += console c++11
CONFIG += app_bundle
CONFIG += qt

SOURCES += \
        Pea.cpp \
        Sunflower.cpp \
        audio.cpp \
        bullet.cpp \
        game.cpp \
        main.cpp \
        mainwindow.cpp \
        over.cpp \
        position.cpp \
        pushbutton.cpp \
        way.cpp \
        zom.cpp

FORMS += \
    mainwindow.ui

HEADERS += \
    Pea.h \
    Sunflower.h \
    audio.h \
    bullet.h \
    game.h \
    mainwindow.h \
    over.h \
    position.h \
    pushbutton.h \
    way.h \
    zom.h

RESOURCES += \
    llb.qrc

DISTFILES +=
