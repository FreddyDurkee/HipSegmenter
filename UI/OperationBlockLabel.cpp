#include "OperationBlockLabel.h"
#include "ui_operationblocklabel.h"
#include <QPainter>

OperationBlockLabel::OperationBlockLabel(const QString &text, QWidget *parent) :
        QLabel(parent),
        ui(new Ui::OperationBlockLabel) {

    ui->setupUi(this);
    this->setText(text);

    int marigin = 12;

    QFontMetrics metric(font());
    QSize size = metric.size(Qt::TextSingleLine, text);

    QLabel::setFixedWidth(size.width() + marigin);
    QLabel::setFixedHeight(size.height() + marigin);

    QImage image(size.width() + marigin, size.height() + marigin, QImage::Format_ARGB32_Premultiplied);
    image.fill(qRgba(0, 0, 0, 0));

    QFont font;
    font.setStyleStrategy(QFont::ForceOutline);

    QLinearGradient gradient(0, 0, 0, image.height() - 1);
    gradient.setColorAt(0.0, Qt::white);
    gradient.setColorAt(0.2, QColor(200, 200, 255));
    gradient.setColorAt(0.8, QColor(200, 200, 255));
    gradient.setColorAt(1.0, QColor(127, 127, 200));

    QPainter painter;
    painter.begin(&image);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(gradient);
    painter.drawRoundedRect(QRectF(0.5, 0.5, image.width() - 1, image.height() - 1),
                            25, 25, Qt::RelativeSize);

    painter.setFont(font);
    painter.setBrush(Qt::black);
    painter.drawText(QRect(QPoint(6, 6), size), Qt::AlignCenter, text);
    painter.end();

    setPixmap(QPixmap::fromImage(image));

    m_labelText = text;
}

OperationBlockLabel::~OperationBlockLabel() {
    delete ui;
}

QString OperationBlockLabel::labelText() const {
    return m_labelText;
}
