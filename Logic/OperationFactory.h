//
// Created by Dominika on 16.05.2019.
//

#ifndef HIPSEGMENTER_OPERATIONFACTORY_H
#define HIPSEGMENTER_OPERATIONFACTORY_H

#include <operations/LoadImageBlock.h>
#include "execution/blocks/BlockWidget.h"
#include "OperationType.h"

using namespace std;

class OperationFactory {
public:
    static Operation* createBlock(OperationType type) {
        if(type == OperationType::LOAD_IMAGE) {
            return new LoadImageBlock();
        }
    }
};


#endif //HIPSEGMENTER_OPERATIONFACTORY_H
