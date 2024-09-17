#ifndef POWER_H
#define POWER_H
#include "Operation.h"
#include <cmath>

class Power : public Operation{
    public:
    double compute(double a, double b) const override;
};

#endif