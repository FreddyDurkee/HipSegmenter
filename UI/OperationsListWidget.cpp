#include "OperationsListWidget.h"
#include "ui_operationslistwidget.h"
#include "OperationsToolBox.h"
#include "OperationBlockWidget.h"
#include <QMimeData>
#include <QDrag>
#include <QDebug>


OperationsListWidget::OperationsListWidget(QWidget *parent) :
        QListWidget(parent),
        ui(new Ui::OperationsListWidget) {
    ui->setupUi(this);

    this->setAcceptDrops(true);

}

OperationsListWidget::~OperationsListWidget() {
    delete ui;
}

void OperationsListWidget::dragMoveEvent(QDragMoveEvent* e)
{
    qDebug() << "jestem w OperationsListWidget::dragMoveEvent";
    if (e->mimeData()->hasFormat(OperationsToolBox::operationBoxesMimeType())) {
        e->setDropAction(Qt::MoveAction);
        e->accept();
    } else
        e->ignore();
}

void OperationsListWidget::dropEvent(QDropEvent* event)
{
    qDebug() << "jestem w OperationsListWidget::dropEvent";
    if (event->mimeData()->hasFormat(OperationsToolBox::operationBoxesMimeType())) {
        const QMimeData *mime = event->mimeData();
        QByteArray itemData = mime->data(OperationsToolBox::operationBoxesMimeType());
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);

        QString text;
        dataStream >> text;

        OperationBlockWidget *item = OperationBlockWidget::of(text);
        item->setParent(this);
        item->setSizeHint(item->size());
        addItem(item);
        QListWidget::setItemWidget(item,item);
//        QListWidgetItem *listWidgetItem = new QListWidgetItem(this);
//        addItem(listWidgetItem);

//        QListWidget::setItemWidget (listWidgetItem, item);

        event->setDropAction(Qt::CopyAction);
        event->accept();
    } else
        event->ignore();
}

void OperationsListWidget::startDrag(Qt::DropActions supportedActions)
{
    qDebug() << "jestem w OperationsListWidget::startDrag";
    QListWidgetItem* item = currentItem();
    QMimeData* mimeData = new QMimeData;
    QByteArray ba;
    ba = item->text().toLatin1().data();
    mimeData->setData(OperationsToolBox::operationBoxesMimeType(), ba);
    QDrag* drag = new QDrag(this);
    drag->setMimeData(mimeData);
    if (drag->exec(Qt::MoveAction) == Qt::MoveAction) {
        delete takeItem(row(item));
        emit itemDroped();
    }
}

void OperationsListWidget::dragEnterEvent(QDragEnterEvent* event)
{
    qDebug() << "jestem w OperationsListWidget::dragEnterEvent";
    if (event->mimeData()->hasFormat(OperationsToolBox::operationBoxesMimeType()))
        event->accept();
    else
        event->ignore();
}

Qt::DropAction OperationsListWidget::supportedDropActions()
{
    return Qt::MoveAction;
}