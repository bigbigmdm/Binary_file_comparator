#-------------------------------------------------
#
# Project created by QtCreator 2025-04-03T14:28:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FileComparer
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    dialogcompare.cpp \
    chunks.cpp \
    color_manager.cpp \
    qhexedit.cpp \
    commands.cpp \
    hexutility.cpp

HEADERS += \
        mainwindow.h \
    dialogcompare.h \
    chunks.h \
    commands.h \
    qhexedit.h \
    color_manager.h \
    hexutility.h

FORMS += \
        mainwindow.ui \
    dialogcompare.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
