//
// Created by Dominika on 19.05.2019.
//

#include "StringParameter.h"
#include <iostream>

bool StringParameter::isValid(string data) {
    if(validator){
        std::cout<<"ok";
    }else{
        std::cout<<"not ok";
    }
    return true;
}

void StringParameter::set(string data) {
    this->data = data;
}


StringParameter::StringParameter(string defaultValue, Parameter::Type type, function<bool(string)> f) : Parameter(
        type), data(defaultValue), validator(f) {

}

const string &StringParameter::getData() const {
    return data;
}
