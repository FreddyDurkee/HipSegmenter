# Created by and for Qt Creator. This file was created for editing the project sources only.
# You may attempt to use it for building too, by modifying this file here.

#TARGET = UI
#TEMPLATE = app

QT += core gui
QT += widgets

CONFIG += c++11

SOURCES += \
    FileSettingWidget.cpp \
        main.cpp \
        mainwindow.cpp \
    BlockWidget.cpp\
    BlockFactory.cpp\
    OperationsToolBox.cpp \
    OperationLabel.cpp \
    OperationsListWidget.cpp \
    BlockListStyle.cpp \
    SettingsDialog.cpp\
    ..\Logic\operations\BlockOperation.cpp\
    ..\Logic\operations\Parameter.cpp\
    ..\Logic\operations\StringParameter.cpp\
    ..\Logic\operations\BlockConfig.cpp\
    ..\Logic\operations\LoadImageBlock.cpp


HEADERS += \
    FileSettingWidget.h \
    ParameterChanger.h \
        mainwindow.h \
    BlockWidget.h\
    BlockFactory.h\
    OperationsToolBox.h \
    OperationLabel.h \
    OperationsListWidget.h \
    BlockListStyle.h \
    SettingsDialog.h\
    ..\Logic\operations\BlockOperation.h\
    ..\Logic\operations\Parameter.h\
    ..\Logic\operations\StringParameter.h\
    ..\Logic\operations\BlockConfig.h\
    ..\Logic\operations\LoadImageBlock.h


FORMS += \
    FileSettingWidget.ui \
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

