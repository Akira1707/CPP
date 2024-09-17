#include "Cotanx.h"

double Cotanx::compute(double a, double b) const {
    if (std::tan(a) == 0){
        throw std::invalid_argument("Cotangent is undefined for this input");
    } 
    return 1.0 / std::tan(a);
}

