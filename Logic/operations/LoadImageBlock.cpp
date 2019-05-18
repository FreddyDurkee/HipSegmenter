//
// Created by Dominika on 16.05.2019.
//

#include "LoadImageBlock.h"
#include <iostream>

using namespace std;

LoadImageBlock::LoadImageBlock() : BlockOperation() {

}

void LoadImageBlock::execute() {
    cout << "Executed LoadImageBlock!" << endl;
}

BlockDefinition::BlockDefinition() {
    definition["directory with images path"] = new FieldDescriptor();
}
