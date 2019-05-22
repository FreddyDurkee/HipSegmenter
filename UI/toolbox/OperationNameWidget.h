#ifndef OPERATIONNAMEWIDGET_H
#define OPERATIONNAMEWIDGET_H

#include <QLabel>
#include "ui_operationnamewidget.h"
#include <OperationType.h>

class OperationNameWidget : public QLabel {
Q_OBJECT

public:
    explicit OperationNameWidget(const QString &text = "", OperationType type = OperationType::NONE, QWidget *parent = 0);

    ~OperationNameWidget();

    QString labelText() const;

    OperationType blockType() const;

private:
    Ui::OperationNameWidget *ui;
    QString m_labelText;
    OperationType m_blockType;

    friend QDataStream &operator<<(QDataStream &ds, OperationNameWidget &widget) {
        int bt = widget.blockType();
        ds << widget.labelText() << bt;
        return ds;
    }

    friend QDataStream &operator>>(QDataStream &ds, OperationNameWidget &widget) {
        QString labelText;
        int bt;
        ds >> labelText >> bt;

        widget.m_labelText = labelText;
        widget.m_blockType = OperationType(bt);

        return ds;
    }
};

#endif // OPERATIONNAMEWIDGET_H
