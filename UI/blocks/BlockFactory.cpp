//
// Created by Dominika on 16.05.2019.
//


#include <operations/LoadImageBlock.h>
#include "BlockFactory.h"
#include "operations/Operation.h"
#include "BlockWidget.h"
#include "BlockType.h"

BlockWidget* BlockFactory::createBlock(QString name, BlockType type) {
    Operation* blkOperation;
    if(type == BlockType::LOAD_IMAGE){
        blkOperation = new LoadImageBlock();
    }
    return new BlockWidget(name, blkOperation);
}
