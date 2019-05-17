#ifndef BLOCKOPERATION_H
#define BLOCKOPERATION_H

#include <memory>

using namespace std;

class BlockOperation
{

public:
    explicit BlockOperation();
    ~BlockOperation();

    void execute();
    static shared_ptr<BlockOperation>  sptr();
    static unique_ptr<BlockOperation>  uptr();

};

using BlockOperationSptr = shared_ptr<BlockOperation> ;
using BlockOperationUptr = unique_ptr<BlockOperation> ;

#endif // BLOCKOPERATION_H
