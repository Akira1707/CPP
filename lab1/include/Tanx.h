#ifndef TANX_H
#define TANX_H
#include "Operation.h"


class Tanx: public Operation{
    public:
    double compute(double a, double b) const override;
};

#endif