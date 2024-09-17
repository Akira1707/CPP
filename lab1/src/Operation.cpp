#include "Cosx.h"
#include "Power.h"
#include "Sinx.h"
#include "Tanx.h"
#include "Cotanx.h"
#include "Logarithm.h"

extern "C" __declspec(dllexport) Operation* createOperation(const char* type) {
    if (strcmp(type, "Cosx") == 0) {
        return new Cosx();
    } else if (strcmp(type, "Power") == 0) {
        return new Power();
    } else if (strcmp(type, "Sinx") == 0) {
        return new Sinx();
    } else if (strcmp(type, "Tanx") == 0) {
        return new Tanx();
    } else if (strcmp(type, "Cotanx") == 0) {
    return new Cotanx();
    } else if (strcmp(type, "Logarithm") == 0) {
        return new Logarithm();
    } else {
        return nullptr;
    }
}
