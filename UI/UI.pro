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
    BlockWidget.cpp\
    BlockFactory.cpp\
    OperationsToolBox.cpp \
    OperationLabel.cpp \
    OperationsListWidget.cpp \
    BlockListStyle.cpp \
    SettingsDialog.cpp\
    ..\Logic\operations\BlockOperation.cpp


HEADERS += \
        mainwindow.h \
    BlockWidget.h\
    BlockFactory.h\
    OperationsToolBox.h \
    OperationLabel.h \
    OperationsListWidget.h \
    BlockListStyle.h \
    SettingsDialog.h\
    ..\Logic\operations\BlockOperation.h


FORMS += \
        mainwindow.ui \
    blockwidget.ui\
    operationstoolbox.ui \
    operationlabel.ui \
    operationslistwidget.ui \
    settingsdialog.ui

INCLUDEPATH = \
    $$PWD/../Logic


DEFINES += QT_DEPRECATED_WARNINGS

RESOURCES += \
    resource.qrc

