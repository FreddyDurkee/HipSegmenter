#ifndef OPERATION_H
#define OPERATION_H

#include <memory>
#include <string>
#include <map>
#include "OperationConfig.h"


using namespace std;


class Operation
{

public:
    Operation();
    ~Operation();

    virtual void execute();
    virtual OperationConfig* getConfig()=0;

};


#endif // OPERATION_H
