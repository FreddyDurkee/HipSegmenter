#include "OperationsListWidget.h"
#include "ui_operationslistwidget.h"
#include "OperationsToolBox.h"
#include "BlockOperation.h"
#include "BlockListStyle.h"
#include "BlockWidget.h"
#include "BlockFactory.h"
#include <QMimeData>
#include <QDrag>
#include <QDebug>


OperationsListWidget::OperationsListWidget(QWidget *parent) :
        QListWidget(parent),
        ui(new Ui::OperationsListWidget) {
    ui->setupUi(this);

    setAcceptDrops(true);
    setDragEnabled(true);
    setDefaultDropAction(Qt::TargetMoveAction);
    setDragDropMode(QAbstractItemView::InternalMove);
    setSelectionBehavior(SelectRows);
    setStyle(new BlockListStyle(style()));
    i = 1;
}

OperationsListWidget::~OperationsListWidget() {
    delete ui;
}

void OperationsListWidget::dragMoveEvent(QDragMoveEvent *e) {
    if (e->mimeData()->hasFormat(OperationsToolBox::operationBoxLabelMimeType())) {
        e->setDropAction(Qt::MoveAction);
        e->accept();
    } else if (e->mimeData()->hasFormat(operationBoxWidgetMimeType())) {
        e->setDropAction(Qt::MoveAction);
        e->accept();
    } else
        e->ignore();
}

void OperationsListWidget::dropEvent(QDropEvent *event) {
    if (event->mimeData()->hasFormat(OperationsToolBox::operationBoxLabelMimeType())) {
        const QMimeData *mime = event->mimeData();
        QByteArray itemData = mime->data(OperationsToolBox::operationBoxLabelMimeType());
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);

        QString text;
        dataStream >> text;

        QString s = QString::number(this->i);
        i += 1;

        BlockWidget *item = BlockFactory::createBlock(text);
        QListWidgetItem *listWidgetItem = new QListWidgetItem(s, this);
        listWidgetItem->setSizeHint(item->size());
        addItem(listWidgetItem);
        setItemWidget(listWidgetItem, item);

        event->setDropAction(Qt::CopyAction);
        event->accept();

    } else if (event->mimeData()->hasFormat(operationBoxWidgetMimeType())) {
        QListWidget::dropEvent(event);
    } else
        event->ignore();
}

void OperationsListWidget::startDrag(Qt::DropActions supportedActions) {
    QListWidgetItem *item = currentItem();
    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
    dataStream << item;

    QMimeData *mimeData = new QMimeData;
    mimeData->setData(operationBoxWidgetMimeType(), itemData);

    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);

    if (drag->exec(Qt::MoveAction) == Qt::MoveAction) {
    }
}

void OperationsListWidget::dragEnterEvent(QDragEnterEvent *event) {
    if (event->mimeData()->hasFormat(OperationsToolBox::operationBoxLabelMimeType()))
        event->accept();
    else if (event->mimeData()->hasFormat(operationBoxWidgetMimeType()))
        event->accept();
    else
        event->ignore();
}

Qt::DropAction OperationsListWidget::supportedDropActions() {
    return Qt::MoveAction;
}

void OperationsListWidget::keyPressEvent(QKeyEvent *e) {
    if(e->key() == Qt::Key_Delete){
        qDeleteAll(selectedItems());
    } else{
        e->ignore();
    }
}

list<BlockOperation*> * OperationsListWidget::getAllItems() {
    list<BlockOperation*> *items = new list<BlockOperation*>();
    for(int i = 0; i < this->count(); ++i)
    {
        QListWidgetItem *listWidgetItem = this->item(i);
        BlockOperation *item = dynamic_cast<BlockOperation*>(this->itemWidget(listWidgetItem));
        items->push_back(item);

    }
    return items;
}
