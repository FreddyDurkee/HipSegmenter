#include "OperationsToolBox.h"
#include "ui_operationstoolbox.h"
#include "OperationBlockWidget.h"
#include "OperationBlockLabel.h"
#include <QMimeData>
#include <QDrag>
#include <QDebug>


OperationsToolBox::OperationsToolBox(QWidget *parent) :
        QToolBox(parent),
        ui(new Ui::OperationsToolBox) {
    ui->setupUi(this);

    setAcceptDrops(true);

    OperationBlockLabel* block = new OperationBlockLabel("operation block");
    QVBoxLayout* processLayout = new QVBoxLayout();
    processLayout->addWidget(block);
    ui->processPage->setLayout(processLayout);



}

OperationsToolBox::~OperationsToolBox() {
    delete ui;
}

void OperationsToolBox::dragEnterEvent(QDragEnterEvent *event)
{
    qDebug() << "jestem w OperationsToolBox::dragEnterEvent";
    if (event->mimeData()->hasFormat(operationBoxesMimeType())) {
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
    qDebug() << "jestem w OperationsToolBox::dragMoveEvent";
    if (event->mimeData()->hasFormat(operationBoxesMimeType())) {
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
    qDebug() << "jestem w OperationsToolBox::dropEvent";
    if (event->mimeData()->hasFormat(operationBoxesMimeType())) {
        const QMimeData *mime = event->mimeData();
        QByteArray itemData = mime->data(operationBoxesMimeType());
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);

        QString text;
        QPoint offset;
        dataStream >> text >> offset;
        OperationBlockLabel *newLabel = new OperationBlockLabel(text, this);
        newLabel->move(event->pos() - offset);
        newLabel->show();
//        newLabel->setAttribute(Qt::WA_DeleteOnClose);

        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
//    } else if (event->mimeData()->hasText()) {
//        QStringList pieces = event->mimeData()->text().split(QRegularExpression(QStringLiteral("\\s+")),
//                                                             QString::SkipEmptyParts);
//        QPoint position = event->pos();
//
//        for (const QString &piece : pieces) {
//            OperationBlockLabel *newLabel = new OperationBlockLabel(piece, this);
//            newLabel->move(position);
//            newLabel->show();
//            newLabel->setAttribute(Qt::WA_DeleteOnClose);
//
//            position += QPoint(newLabel->width(), 0);
//        }

        event->acceptProposedAction();
    } else {
        event->ignore();
    }
}

void OperationsToolBox::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "jestem w OperationsToolBox::mousePressEvent";
    OperationBlockLabel *child = dynamic_cast<OperationBlockLabel*>(childAt(event->pos()));
    if (!child)
        return;

    QPoint hotSpot = event->pos() - child->pos();

    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
    dataStream << child->labelText() << QPoint(hotSpot);

    QMimeData *mimeData = new QMimeData;
    mimeData->setData(operationBoxesMimeType(), itemData);
    mimeData->setText(child->labelText());

    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(*child->pixmap());
    drag->setHotSpot(hotSpot);

//    child->hide();

    if (drag->exec(Qt::MoveAction | Qt::CopyAction, Qt::CopyAction) == Qt::MoveAction)
        child->close();
    else
        child->show();
}
