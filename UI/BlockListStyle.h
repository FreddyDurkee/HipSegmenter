//
// Created by Dominika on 22.03.2019.
//

#ifndef HIPSEGMENTER_BLOCKLISTSTYLE_H
#define HIPSEGMENTER_BLOCKLISTSTYLE_H

#include <QProxyStyle>


class BlockListStyle : public QProxyStyle{
public:

    BlockListStyle(QStyle* style = 0);

    void drawPrimitive ( PrimitiveElement element, const QStyleOption * option, QPainter * painter, const QWidget * widget = 0 ) const;

};


#endif //HIPSEGMENTER_BLOCKLISTSTYLE_H
