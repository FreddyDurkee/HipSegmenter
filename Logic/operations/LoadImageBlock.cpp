//
// Created by Dominika on 16.05.2019.
//

#include "LoadImageBlock.h"
#include "parameters/Parameter.h"
#include "Operation.h"
#include "parameters/StringParameter.h"
#include "Validators.h"


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
LoadImageBlock::LoadImageConfig::LoadImageConfig(string defaultPath) {
    this->path = new StringParameter(defaultPath, Parameter::Type::File, Validators::always<string> );
}

LoadImageBlock::LoadImageConfig::~LoadImageConfig() {
    delete path;
}

map<string, Parameter *> LoadImageBlock::LoadImageConfig::getParams() {
    map<string, Parameter*> params;
    params["path"] = path;
    return params;
}


