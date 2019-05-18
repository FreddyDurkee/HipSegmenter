//
// Created by Dominika on 18.05.2019.
//

#include "FieldDescriptor.h"

FieldDescriptor::FieldDescriptor(string widgetTypeName, string defaultPath) {
    widgetType = widgetTypeName;
    this->defaultPath = defaultPath;
}

FieldDescriptor::~FieldDescriptor() {

}
