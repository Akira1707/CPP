#include "Logarithm.h"

double Logarithm::compute(double a, double b) const {
    if (a <= 0 || a == 1 || b <= 0){
        throw std::invalid_argument("Invalid input for logarithm");
    }
    return std::log10(b)/log10(a);
}

