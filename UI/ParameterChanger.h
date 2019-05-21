#ifndef PARAMETERCHANGER_H
#define PARAMETERCHANGER_H

#include <operations/parameters/Parameter.h>

class ParameterChanger{

public:
   virtual bool apply() = 0;
   virtual void reset() = 0;
};

#endif // PARAMETERCHANGER_H
