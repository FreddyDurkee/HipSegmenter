#ifndef BLOCKOPERATION_H
#define BLOCKOPERATION_H

#include <memory>
#include <string>
#include <map>
#include "Parameter.h"
#include "BlockConfig.h"


using namespace std;


class BlockOperation
{

public:
    BlockOperation();
    ~BlockOperation();

    virtual void execute();
    virtual BlockConfig* getConfig()=0;

};


#endif // BLOCKOPERATION_H
