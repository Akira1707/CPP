#ifndef COSX_H
#define COSX_H
#include "Operation.h"
#include <cmath> 

class Cosx: public Operation{
    public:
    double compute(double a, double b) const override;
};

#endif