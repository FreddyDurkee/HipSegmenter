#ifndef OPERATIONBLOCKLABEL_H
#define OPERATIONBLOCKLABEL_H

#include <QLabel>
#include "ui_operationlabel.h"
#include <blocks/BlockType.h>

class OperationBlockLabel : public QLabel {
Q_OBJECT

public:
    explicit OperationBlockLabel(const QString &text = "", BlockType type = BlockType::NONE, QWidget *parent = 0);

    ~OperationBlockLabel();

    QString labelText() const;

    BlockType blockType() const;

private:
    Ui::OperationBlockLabel *ui;
    QString m_labelText;
    BlockType m_blockType;

    friend QDataStream &operator<<(QDataStream &ds, OperationBlockLabel &widget) {
        int bt = widget.blockType();
        ds << widget.labelText() << bt;
        return ds;
    }

    friend QDataStream &operator>>(QDataStream &ds, OperationBlockLabel &widget) {
        QString labelText;
        int bt;
        ds >> labelText >> bt;

        widget.m_labelText = labelText;
        widget.m_blockType = BlockType(bt);

        return ds;
    }
};

#endif // OPERATIONBLOCKLABEL_H
