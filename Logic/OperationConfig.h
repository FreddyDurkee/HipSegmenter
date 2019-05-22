//
// Created by Dominika on 19.05.2019.
//

#ifndef HIPSEGMENTER_OPERATIONCONFIG_H
#define HIPSEGMENTER_OPERATIONCONFIG_H


#include <string>
#include <map>
#include "Parameter.h"


class OperationConfig {
public:
    OperationConfig();
    ~OperationConfig();
    virtual map<string, Parameter*> getParams() = 0;
};


#endif //HIPSEGMENTER_OPERATIONCONFIG_H
