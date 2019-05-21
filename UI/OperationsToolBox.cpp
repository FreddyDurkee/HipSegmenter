#include "OperationsToolBox.h"
#include "ui_operationstoolbox.h"
#include "operations/Operation.h"
#include "OperationLabel.h"
#include <QMimeData>
#include <QDrag>
#include <QDebug>


OperationsToolBox::OperationsToolBox(QWidget *parent) :
        QToolBox(parent),
        ui(new Ui::OperationsToolBox) {
    ui->setupUi(this);

    setAcceptDrops(true);

    OperationBlockLabel* loadImageBlock = new OperationBlockLabel("load image");
    QVBoxLayout* processLayout = new QVBoxLayout();
    processLayout->addWidget(loadImageBlock);
    ui->processPage->setLayout(processLayout);
}

OperationsToolBox::~OperationsToolBox() {
    delete ui;
}

void OperationsToolBox::dragEnterEvent(QDragEnterEvent *event)
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

void OperationsToolBox::dragMoveEvent(QDragMoveEvent *event)
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

void OperationsToolBox::dropEvent(QDropEvent *event)
{
    if (event->mimeData()->hasFormat(operationBoxLabelMimeType())) {
        const QMimeData *mime = event->mimeData();
        QByteArray itemData = mime->data(operationBoxLabelMimeType());
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);

        QString text;
        QPoint offset;
        dataStream >> text >> offset;
        OperationBlockLabel *newLabel = new OperationBlockLabel(text, this);
        newLabel->move(event->pos() - offset);
        newLabel->show();

        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }

        event->acceptProposedAction();
    } else {
        event->ignore();
    }
}

void OperationsToolBox::mousePressEvent(QMouseEvent *event)
{
    OperationBlockLabel *child = dynamic_cast<OperationBlockLabel*>(childAt(event->pos()));
    if (!child)
        return;

    QPoint hotSpot = event->pos() - child->pos();

    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
    dataStream << child->labelText() << QPoint(hotSpot);

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
