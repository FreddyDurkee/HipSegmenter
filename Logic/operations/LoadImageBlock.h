//
// Created by Dominika on 16.05.2019.
//

#ifndef HIPSEGMENTER_LOADIMAGEBLOCK_H
#define HIPSEGMENTER_LOADIMAGEBLOCK_H


#include <string>
#include <map>
#include "BlockOperation.h"
#include "FieldDescriptor.h"

using namespace std;

class LoadImageBlock : public BlockOperation
{
public:
    explicit LoadImageBlock();
    ~LoadImageBlock();
    void execute();

};

class BlockDefinition{
public:
    BlockDefinition();
    ~BlockDefinition();

    void validate();

private:
    map<string, FieldDescriptor*> definition;
};


#endif //HIPSEGMENTER_LOADIMAGEBLOCK_H
