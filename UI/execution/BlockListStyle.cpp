//
// Created by Dominika on 22.03.2019.
//

#include <QStyleOption>
#include "BlockListStyle.h"
#include "OperationsListWidget.h"
#include <QDebug>

BlockListStyle::BlockListStyle(QStyle *style) : QProxyStyle(style) {

}

void BlockListStyle::drawPrimitive(PrimitiveElement element, const QStyleOption *option, QPainter *painter,
                                   const QWidget *widget) const {
    if (element == QStyle::PE_IndicatorItemViewItemDrop) {
        QStyleOption opt(*option);
        if (widget) {
            opt.rect.setRight(widget->width());
            const QPoint &mouse_pos = QCursor::pos();
            const OperationsListWidget *olw = dynamic_cast<const OperationsListWidget *>(widget);
            const QPoint &widget_coor = olw->mapFromGlobal(mouse_pos);
            QWidget *child = olw->childAt(widget_coor);
            if (child != NULL) {
                const QPoint &child_pos = child->pos();
                opt.rect.moveTop(child_pos.y());
            }
        }
        QProxyStyle::drawPrimitive(element, &opt, painter, widget);
        return;
    } else {

        QProxyStyle::drawPrimitive(element, option, painter, widget);
    }
}
