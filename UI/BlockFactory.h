//
// Created by Dominika on 16.05.2019.
//

#ifndef HIPSEGMENTER_BLOCKFACTORY_H
#define HIPSEGMENTER_BLOCKFACTORY_H

#include <QString>
#include "BlockWidget.h"

using namespace std;

class BlockFactory {
public:
    static BlockWidget* createBlock(QString operationName);

};


#endif //HIPSEGMENTER_BLOCKFACTORY_H
