# Created by and for Qt Creator. This file was created for editing the project sources only.
# You may attempt to use it for building too, by modifying this file here.

#TARGET = UI
#TEMPLATE = app

QT += core gui
QT += widgets

CONFIG += c++11

SOURCES += \
    FileGetterWidget.cpp \
        main.cpp \
        mainwindow.cpp \
    blocks\BlockWidget.cpp\
    blocks\BlockFactory.cpp\
    OperationsToolWidget.cpp \
    OperationLabel.cpp \
    OperationsListWidget.cpp \
    BlockListStyle.cpp \
    SettingsDialog.cpp\
    ..\Logic\operations\Operation.cpp\
    ..\Logic\operations\parameters\Parameter.cpp\
    ..\Logic\operations\parameters\StringParameter.cpp\
    ..\Logic\operations\OperationConfig.cpp\
    ..\Logic\operations\LoadImageBlock.cpp


HEADERS += \
    FileGetterWidget.h \
    FileUtil.h \
    ParameterChanger.h \
    blocks/BlockType.h \
        mainwindow.h \
    blocks\BlockWidget.h\
    blocks\BlockFactory.h\
    OperationsToolWidget.h \
    OperationLabel.h \
    OperationsListWidget.h \
    BlockListStyle.h \
    SettingsDialog.h\
    ..\Logic\operations\Operation.h\
    ..\Logic\operations\parameters\Parameter.h\
    ..\Logic\operations\parameters\StringParameter.h\
    ..\Logic\operations\OperationConfig.h\
    ..\Logic\operations\LoadImageBlock.h


FORMS += \
    FileGetterWidget.ui \
        mainwindow.ui \
    blocks\blockwidget.ui\
    operationstoolbox.ui \
    operationlabel.ui \
    operationslistwidget.ui \
    settingsdialog.ui

INCLUDEPATH = \
    $$PWD/../Logic


DEFINES += QT_DEPRECATED_WARNINGS

RESOURCES += \
    resource.qrc

