//
// Created by Dominika on 18.05.2019.
//

#include "Parameter.h"


Parameter::~Parameter() {

}

Parameter::Parameter(Parameter::Type parameterType) : parameterType(parameterType) {}

Parameter::Type Parameter::getParameterType() const {
    return parameterType;
}
