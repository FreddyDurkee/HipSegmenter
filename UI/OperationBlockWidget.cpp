#include "OperationBlockWidget.h"
#include <QString>

OperationBlockWidget::OperationBlockWidget(QListWidget *parent) :
    QWidget(parent),
    QListWidgetItem(parent),
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
    return  ui->operationName->text();
}




