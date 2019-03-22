#ifndef OPERATIONSLISTWIDGET_H
#define OPERATIONSLISTWIDGET_H

#include <QListWidget>
#include <QDragMoveEvent>
#include "ui_operationslistwidget.h"

class OperationsListWidget : public QListWidget
{
    Q_OBJECT

public:
    explicit OperationsListWidget(QWidget *parent = 0);
    ~OperationsListWidget();

protected:
    void dragMoveEvent(QDragMoveEvent* e);
    void dropEvent(QDropEvent* event);
    void startDrag(Qt::DropActions supportedActions);
    void dragEnterEvent(QDragEnterEvent* event);
    Qt::DropAction supportedDropActions();
signals:
    void itemDroped();

private:
    Ui::OperationsListWidget *ui;
};

#endif // OPERATIONSLISTWIDGET_H
