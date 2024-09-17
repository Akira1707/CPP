#include <iostream>
#include <windows.h>
#include "Operation.h"

typedef Operation* (*CreateOperation)(const char*);

void performOperation(const std::string& operationName, double a, double b) {
    HMODULE lib = LoadLibrary("lab1.dll");
    if (!lib) {
        std::cerr << "Failed to load library" << std::endl;
        return;
    }

    CreateOperation createOperation = (CreateOperation)GetProcAddress(lib, "createOperation");
    if (!createOperation) {
        std::cerr << "Failed to get function" << std::endl;
        FreeLibrary(lib);
        return;
    }

    Operation* op = createOperation(operationName.c_str());
    if (!op) {
        std::cerr << "Failed to create operation: " << operationName << std::endl;
        FreeLibrary(lib);
        return;
    }

    try {
        std::cout << "Result of " << operationName << ": " << op->compute(a, b) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    delete op;
    FreeLibrary(lib);
}

int main() {
    performOperation("Power", 5, 3);
    performOperation("Sinx", 3.14, 0);
    performOperation("Cosx", 3.14, 0);
    performOperation("Tanx", 3.14/4, 0);
    performOperation("Logarithm", 10, 100);
    return 0;
}

