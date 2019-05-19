//
// Created by Dominika on 16.05.2019.
//

#include "LoadImageBlock.h"
#include "Parameter.h"
#include "BlockOperation.h"
#include "StringParameter.h"


#include <iostream>

using namespace std;

// *** definitions for LoadImageBlock:

LoadImageBlock::LoadImageBlock() {
    config = new LoadImageConfig(".");
}

void LoadImageBlock::execute() {
    cout << "Executed LoadImageBlock! " << this->config->path->getData()<<endl;
}

BlockConfig* LoadImageBlock::getConfig() {
    return config;
}

LoadImageBlock::~LoadImageBlock() {
    delete config;
}

// *** definitions for LoadImageConfig

namespace Validators{
    bool always(string val){
        return true;
    }
}

LoadImageBlock::LoadImageConfig::LoadImageConfig(string defaultPath) {
    this->path = new StringParameter(defaultPath, Parameter::Type::File, Validators::always );
}

LoadImageBlock::LoadImageConfig::~LoadImageConfig() {
    delete path;
}

map<string, Parameter *> LoadImageBlock::LoadImageConfig::getParams() {
    map<string, Parameter*> params;
    params["path"] = path;
    return params;
}


