#ifndef OPERATIONSTOOLWIDGET_H
#define OPERATIONSTOOLWIDGET_H

#include <QToolBox>
#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include "ui_operationstoolwidget.h"

class OperationsToolWidget : public QToolBox
{
    Q_OBJECT

public:
    explicit OperationsToolWidget(QWidget *parent = 0);
    static inline QString operationBoxLabelMimeType(){ return QStringLiteral("application/x-operationboxlabel"); }
    ~OperationsToolWidget();

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;

    void dragMoveEvent(QDragMoveEvent *event) override;

    void dropEvent(QDropEvent *event) override;

    void mousePressEvent(QMouseEvent *event) override;

private:
    Ui::OperationsToolWidget *ui;
};

#endif // OPERATIONSTOOLWIDGET_H
