//
// Created by Dominika on 19.05.2019.
//

#ifndef HIPSEGMENTER_BLOCKCONFIG_H
#define HIPSEGMENTER_BLOCKCONFIG_H


#include <string>
#include <map>
#include "Parameter.h"

class BlockConfig {
public:
    BlockConfig();
    ~BlockConfig();
    virtual map<string, Parameter*> getParams() = 0;
};


#endif //HIPSEGMENTER_BLOCKCONFIG_H
