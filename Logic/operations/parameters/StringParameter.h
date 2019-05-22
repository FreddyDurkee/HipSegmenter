//
// Created by Dominika on 19.05.2019.
//

#ifndef HIPSEGMENTER_STRINGPARAMETER_H
#define HIPSEGMENTER_STRINGPARAMETER_H

#include "../../Parameter.h"
#include <string>
#include <functional>

using namespace std;

class StringParameter : public Parameter {
private:
    string data;
    function<bool(string)> validator;

public:
    bool isValid(string data);
    void set(string data);
    const string &getData() const;

    StringParameter(string defaultValue, Type type, function<bool(string)> f);
};


#endif //HIPSEGMENTER_STRINGPARAMETER_H
