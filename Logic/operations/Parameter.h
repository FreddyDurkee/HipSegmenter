//
// Created by Dominika on 18.05.2019.
//

#ifndef HIPSEGMENTER_PARAMETER_H
#define HIPSEGMENTER_PARAMETER_H

#include <string>

using namespace std;


class Parameter {
public:
    enum Type {File};
    Parameter(Type parameterType);
    virtual ~Parameter() = 0;

    Type getParameterType() const;

protected:
    Type parameterType;
};


#endif //HIPSEGMENTER_PARAMETER_H
