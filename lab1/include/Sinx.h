#ifndef SINX_H
#define SINX_H
#include "Operation.h"
#include <cmath>


class Sinx: public Operation{
    public:
    double compute(double a, double b) const override;
};
#endif