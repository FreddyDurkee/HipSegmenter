//
// Created by Dominika on 16.05.2019.
//

#ifndef HIPSEGMENTER_LOADIMAGEBLOCK_H
#define HIPSEGMENTER_LOADIMAGEBLOCK_H


#include <QtWidgets/QLabel>
#include "BlockOperation.h"

class LoadImageBlock : public BlockOperation
{
public:
    explicit LoadImageBlock();
    ~LoadImageBlock();
    void execute();

};


#endif //HIPSEGMENTER_LOADIMAGEBLOCK_H
