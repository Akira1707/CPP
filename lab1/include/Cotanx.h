#ifndef COTANX_H
#define COTANX_H
#include "Operation.h"
#include <cmath>
#include <stdexcept>

class Cotanx: public Operation{
    public:
    double compute(double a, double b) const override;
};

#endif