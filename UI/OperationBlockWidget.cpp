#include "OperationBlockWidget.h"
#include <QString>
#include "SettingsDialog.h"
#include <iostream>


OperationBlockWidget::OperationBlockWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::OperationBlockWidget)
{
    ui->setupUi(this);
}

OperationBlockWidget::~OperationBlockWidget()
{
    delete ui;
}

OperationBlockWidget *OperationBlockWidget::of(const QString &text) {
    OperationBlockWidget* operationBlock = new OperationBlockWidget();
    operationBlock->setText(text);
    return operationBlock;
}

void OperationBlockWidget::setText(QString text) {
    ui->operationName->setText(text);
}

QString OperationBlockWidget::getText() const
{
    QString name = ui->operationName->text();
    return  ui->operationName->text();
}

void OperationBlockWidget::mousePressEvent(QMouseEvent *event) {

}





void OperationBlockWidget::on_settingButton_clicked()
{
    SettingsDialog* dialog = new SettingsDialog();
    dialog->exec();

}

void OperationBlockWidget::execute() {
//    TO DO: implement method

    cout << "Executed!" << this->getText().toStdString() << endl;
}


