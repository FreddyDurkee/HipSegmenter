#ifndef OPERATIONBLOCKLABEL_H
#define OPERATIONBLOCKLABEL_H

#include <QLabel>
#include "ui_operationblocklabel.h"

class OperationBlockLabel : public QLabel
{
    Q_OBJECT

public:
    explicit OperationBlockLabel(const QString &text, QWidget *parent = 0);
    ~OperationBlockLabel();
    QString labelText() const;

private:
    Ui::OperationBlockLabel *ui;
    QString m_labelText;
};

#endif // OPERATIONBLOCKLABEL_H
