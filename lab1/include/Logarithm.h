#ifndef LOGARITHM_H
#define LOGARITHM_H
#include "Operation.h"
#include <cmath>
#include <stdexcept>

class Logarithm: public Operation{
    public:
    double compute(double a, double b) const override;
};

#endif