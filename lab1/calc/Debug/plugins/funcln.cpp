#include <cmath>
#include <stdexcept>

extern "C" __declspec(dllexport) double calculate(double x) {
    if (x < 0) {
        throw std::invalid_argument("Input ln(x) must be non-negative");
    }
    return log(x);
}
