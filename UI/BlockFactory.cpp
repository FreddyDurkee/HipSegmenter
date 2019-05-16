//
// Created by Dominika on 16.05.2019.
//

#include "BlockFactory.h"
#include "BlockOperation.h"

BlockWidget* BlockFactory::createBlock(QString operationName) {
    BlockOperation *blkOperation = new BlockOperation();
    return new BlockWidget(operationName, blkOperation);
}
