#ifndef OPERATION_H
#define OPERATION_H

#include <memory>
#include <string>
#include <map>
#include "BlockConfig.h"


using namespace std;


class Operation
{

public:
    Operation();
    ~Operation();

    virtual void execute();
    virtual BlockConfig* getConfig()=0;

};


#endif // OPERATION_H
