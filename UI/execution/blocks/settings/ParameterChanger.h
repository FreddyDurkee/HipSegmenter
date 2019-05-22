#ifndef PARAMETERCHANGER_H
#define PARAMETERCHANGER_H


class ParameterChanger{

public:
   virtual bool apply() = 0;
   virtual void reset() = 0;
};

#endif // PARAMETERCHANGER_H
