//
// Created by Dominika on 18.05.2019.
//

#ifndef HIPSEGMENTER_FIELDDESCRIPTOR_H
#define HIPSEGMENTER_FIELDDESCRIPTOR_H

#include <string>

using namespace std;


class FieldDescriptor {
public:
    FieldDescriptor(string widgetTypeName, string defaultPath);
    FieldDescriptor(string widgetTypeName, string defaultPath);
    ~FieldDescriptor();
private:
    string widgetType;
    string defaultPath;
    int defaultInt;
    double defaultDouble;

};


#endif //HIPSEGMENTER_FIELDDESCRIPTOR_H
