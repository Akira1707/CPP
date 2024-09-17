#ifndef OPERATION_H
#define OPERATION_H

class Operation{
    public:
    virtual ~Operation() = default;
    virtual double compute(double a, double b) const = 0;
};
#endif