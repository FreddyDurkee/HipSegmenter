# Created by and for Qt Creator. This file was created for editing the project sources only.
# You may attempt to use it for building too, by modifying this file here.

#TARGET = UI
#TEMPLATE = app

QT += core gui
QT += widgets

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    OperationBlockWidget.cpp \
    OperationsToolBox.cpp \
    OperationBlockLabel.cpp \
    OperationsListWidget.cpp \
    BlockListStyle.cpp

HEADERS += \
        mainwindow.h \
    OperationBlockWidget.h \
    OperationsToolBox.h \
    OperationBlockLabel.h \
    OperationsListWidget.h \
    BlockListStyle.h

FORMS += \
        mainwindow.ui \
    operationblockwidget.ui \
    operationstoolbox.ui \
    operationblocklabel.ui \
    operationslistwidget.ui

INCLUDEPATH = \
    $$PWD/../Logic

DEFINES += QT_DEPRECATED_WARNINGS

RESOURCES += \
    resource.qrc

