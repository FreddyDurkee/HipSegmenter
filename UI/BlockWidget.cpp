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
    this->operation = blkOperation;
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
    SettingsDialog *dialog = new SettingsDialog();
    dialog->exec();

}

void BlockWidget::execute() {
    operation->execute();
}

shared_ptr<BlockWidget>  BlockWidget::sptr(QString qString, BlockOperation *pOperation) {
    return make_shared<BlockWidget>(qString, pOperation);
}

unique_ptr<BlockWidget> BlockWidget::uptr(QString qString, BlockOperation *pOperation) {
    return make_unique<BlockWidget>(qString, pOperation);
}

