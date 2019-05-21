//
// Created by Dominika on 16.05.2019.
//

#ifndef HIPSEGMENTER_BLOCKFACTORY_H
#define HIPSEGMENTER_BLOCKFACTORY_H

#include <QString>
#include "blocks/BlockWidget.h"
#include "BlockType.h"

using namespace std;

class BlockFactory {
public:
    static BlockWidget* createBlock(QString name, BlockType type);

};


#endif //HIPSEGMENTER_BLOCKFACTORY_H
