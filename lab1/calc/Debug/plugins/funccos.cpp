#include <cmath>

extern "C" __declspec(dllexport) double calculate(double x) {
    return cos(x * M_PI / 180.0);
}