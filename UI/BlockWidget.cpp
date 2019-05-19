//
// Created by Dominika on 16.05.2019.
//

#include "BlockWidget.h"
#include "SettingsDialog.h"

BlockWidget::BlockWidget(QString name, BlockOperation* blkOperation, QWidget *parent) :
        QWidget(parent),
        ui(new Ui::BlockWidget) {
    ui->setupUi(this);
    ui->operationName->setText(name);
    operation = blkOperation;
    settingsDialog = new SettingsDialog(operation->getConfig());
}

BlockWidget::~BlockWidget() {
    delete ui;
}

QString BlockWidget::getText() const {
    QString name = ui->operationName->text();
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


