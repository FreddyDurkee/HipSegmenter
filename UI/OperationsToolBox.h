#ifndef OPERATIONSTOOLBOX_H
#define OPERATIONSTOOLBOX_H

#include <QToolBox>
#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include "ui_operationstoolbox.h"

class OperationsToolBox : public QToolBox
{
    Q_OBJECT

public:
    explicit OperationsToolBox(QWidget *parent = 0);
    static inline QString operationBoxesMimeType(){ return QStringLiteral("application/x-operationbox"); }
    ~OperationsToolBox();

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;

    void dragMoveEvent(QDragMoveEvent *event) override;

    void dropEvent(QDropEvent *event) override;

    void mousePressEvent(QMouseEvent *event) override;

private:
    Ui::OperationsToolBox *ui;
};

#endif // OPERATIONSTOOLBOX_H
