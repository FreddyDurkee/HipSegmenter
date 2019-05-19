//
// Created by Dominika on 16.05.2019.
//

#include <operations/LoadImageBlock.h>
#include "BlockFactory.h"
#include "operations/BlockOperation.h"

BlockWidget* BlockFactory::createBlock(QString operationName) {
    BlockOperation* blkOperation;
    if(operationName == "load image"){
        blkOperation = new LoadImageBlock();
    }
    return new BlockWidget(operationName, blkOperation);
}
