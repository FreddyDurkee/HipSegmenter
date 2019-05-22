#include "OperationsToolWidget.h"
#include "ui_operationstoolwidget.h"
#include "Operation.h"
#include "OperationNameWidget.h"
#include <QMimeData>
#include <QDrag>
#include <QDebug>


OperationsToolWidget::OperationsToolWidget(QWidget *parent) :
        QToolBox(parent),
        ui(new Ui::OperationsToolWidget) {
    ui->setupUi(this);

    setAcceptDrops(true);

    OperationNameWidget* loadImageBlock = new OperationNameWidget("load image",OperationType::LOAD_IMAGE);
    QVBoxLayout* processLayout = new QVBoxLayout();
    processLayout->addWidget(loadImageBlock);
    ui->processPage->setLayout(processLayout);
}

OperationsToolWidget::~OperationsToolWidget() {
    delete ui;
}

void OperationsToolWidget::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat(operationBoxLabelMimeType())) {
        if (children().contains(event->source())) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else if (event->mimeData()->hasText()) {
        event->acceptProposedAction();
    } else {
        event->ignore();
    }
}

void OperationsToolWidget::dragMoveEvent(QDragMoveEvent *event)
{
    if (event->mimeData()->hasFormat(operationBoxLabelMimeType())) {
        event->ignore();
    } else {
        event->ignore();
    }
}

void OperationsToolWidget::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasFormat(operationBoxLabelMimeType())) {
        event->ignore();
    } else {
        event->ignore();
    }
}

void OperationsToolWidget::mousePressEvent(QMouseEvent *event)
{
    OperationNameWidget *child = dynamic_cast<OperationNameWidget*>(childAt(event->pos()));
    if (!child)
        return;

    QPoint hotSpot = event->pos() - child->pos();

    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
    dataStream << *child;

    QMimeData *mimeData = new QMimeData;
    mimeData->setData(operationBoxLabelMimeType(), itemData);
    mimeData->setText(child->labelText());

    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(*child->pixmap());
    drag->setHotSpot(hotSpot);

    if (drag->exec(Qt::MoveAction | Qt::CopyAction, Qt::CopyAction) == Qt::MoveAction)
        child->close();
    else
        child->show();
}
