//
// Created by Dominika on 16.05.2019.
//

#ifndef HIPSEGMENTER_OPERATIONBLOCKWIDGETFACTORY_H
#define HIPSEGMENTER_OPERATIONBLOCKWIDGETFACTORY_H

#include <QString>
#include "BlockWidget.h"

using namespace std;

class BlockFactory {
public:
    static BlockWidget* createBlock(QString operationName);

};


#endif //HIPSEGMENTER_OPERATIONBLOCKWIDGETFACTORY_H
