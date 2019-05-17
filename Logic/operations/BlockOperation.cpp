#include "BlockOperation.h"
#include <iostream>


BlockOperation::BlockOperation()
{
}

BlockOperation::~BlockOperation()
{

}


void BlockOperation::execute() {
//    TO DO: implement method

    cout << "Executed!"<< endl;
}


shared_ptr<BlockOperation>  BlockOperation::sptr() {
    return make_shared<BlockOperation>();
}

unique_ptr<BlockOperation>  BlockOperation::uptr() {
    return make_unique<BlockOperation>();
}

