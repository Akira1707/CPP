#include <cmath>
extern "C" __declspec(dllexport) double calculate(double x) {
    return exp(x);
}
