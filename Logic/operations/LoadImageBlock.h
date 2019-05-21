//
// Created by Dominika on 16.05.2019.
//

#ifndef HIPSEGMENTER_LOADIMAGEBLOCK_H
#define HIPSEGMENTER_LOADIMAGEBLOCK_H


#include <string>
#include <map>
#include "Operation.h"
#include "BlockConfig.h"
#include "parameters/Parameter.h"
#include "parameters/StringParameter.h"


using namespace std;



class LoadImageBlock : public Operation
{
    /// Inner classes
    class LoadImageConfig : public  BlockConfig{
    public:
        LoadImageConfig(string defaultPath) ;
        ~LoadImageConfig();

        map<string, Parameter *> getParams() override;

        StringParameter* path;
    };
    /// Inner classes - end

public:
    LoadImageBlock();
    ~LoadImageBlock();
    BlockConfig* getConfig() override;
    void execute();
private:
    LoadImageConfig* config;

};



#endif //HIPSEGMENTER_LOADIMAGEBLOCK_H
