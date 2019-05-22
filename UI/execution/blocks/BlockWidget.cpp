//
// Created by Dominika on 16.05.2019.
//

#include "BlockWidget.h"
#include "SettingsDialog.h"

BlockWidget::BlockWidget(QString name, Operation* blkOperation, QWidget *parent) :
        QWidget(parent),
        ui(new Ui::BlockWidget) {
    ui->setupUi(this);
    ui->operationName->setText(name);
    operation = blkOperation;
    settingsDialog = new SettingsDialog(operation->getConfig(), name);
}

BlockWidget::~BlockWidget() {
    delete ui;
}

QString BlockWidget::getText() const {
    return ui->operationName->text();
}

void BlockWidget::mousePressEvent(QMouseEvent *event) {

}


void BlockWidget::on_settingButton_clicked() {
    settingsDialog->show();
}

void BlockWidget::execute() {
    operation->execute();
}

BlockWidget *BlockWidget::of(QString name, Operation *operation) {
    return new BlockWidget(name, operation);
}


