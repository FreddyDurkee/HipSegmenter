//
// Created by Dominika on 16.05.2019.
//


#include <operations/LoadImageBlock.h>
#include "BlockFactory.h"
#include "operations/Operation.h"
#include "BlockWidget.h"

BlockWidget* BlockFactory::createBlock(QString operationName) {
    Operation* blkOperation;
    if(operationName == "load image"){
        blkOperation = new LoadImageBlock();
    }
    return new BlockWidget(operationName, blkOperation);
}
