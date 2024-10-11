#include <cmath>
#include <stdexcept>

extern "C" __declspec(dllexport) double calculate(double x) {
    if (tan(x) == 0) {
        throw std::invalid_argument("Cotangent is undefined for this input");
    }
    return 1.0 / tan(x);
}