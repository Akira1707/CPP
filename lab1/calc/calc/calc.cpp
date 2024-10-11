#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <cmath>
#include <windows.h>

using namespace std;

typedef double (*Function)(double);

HMODULE loadMathLibrary(const string& libraryName) {
    HMODULE hModule = LoadLibraryA(libraryName.c_str());
    if (!hModule) {
        cerr << "Could not load the DLL: " << libraryName << endl;
        exit(EXIT_FAILURE);
    }
    return hModule;
}

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^' ;
}

int priority(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    if (isalpha(op)) return 3;
    return 0;
}

bool higherPriority(char a, char b) {
    return priority(a) >= priority(b);
}

string infixToPostfix(const string& expression) {
    stack<string> s;
    string postfix = "";
    string number = "";
    string function = "";
    int check = 0;

    for (char c : expression) {
        if (isspace(c)) continue;
        if (isdigit(c) || c == '.') {
            number += c;
            if (!function.empty()) {
                check = 1;
                while (!s.empty() && isOperator(s.top()[0]) && higherPriority(s.top()[0], 'a')) {
                    postfix += s.top();
                    postfix += ' ';
                    s.pop();
                }
                s.push(function);
                function = "";
            }
        }
        else {
            if (!number.empty()) {
                postfix += number + ' ';
                number = "";
            }
            if (isalpha(c)) {
                function += c;
            }
            else {
                if (!function.empty()) {
                    check = 1;
                    while (!s.empty() && isOperator(s.top()[0]) && higherPriority(s.top()[0], 'a')) {
                        postfix += s.top();
                        postfix += ' ';
                        s.pop();
                    }
                    s.push(function);
                    function = "";
                }
                if (c == '(' && check != 1) {
                    string l = "";
                    l += c;
                    s.push(l);
                }
                else if (c == ')') {
                    if (check == 1) {       
                        check = 0;
                        continue;
                    }
                    while (!s.empty() && s.top()[0] != '(') {
                        postfix += s.top();
                        postfix += ' ';
                        s.pop();
                    }
                    s.pop();
                }
                else if (isOperator(c)) {
                    while (!s.empty() && isOperator(s.top()[0]) && higherPriority(s.top()[0], c)) {
                        postfix += s.top();
                        postfix += ' ';
                        s.pop();
                    }

                    string l = "";
                    l += c;
                    s.push(l);                 }
            }
        }
    }

    if (!number.empty()) {
        postfix += number + ' ';
    }

    while (!s.empty()) {
        postfix += s.top();
        postfix += ' ';
        s.pop();
    }

    return postfix;
}

double evaluatePostfix(const string& postfix) {
    stack<double> s;
    string number = "";
    string function = "";

    for (char c : postfix) {
        if (isdigit(c) || c == '.') {
            number += c;
        }
        else if (isalpha(c)) {
            function += c;
        }
        else if (isspace(c)) {
            if (!number.empty()) {
                s.push(stod(number));
                number = "";
            }
            if (!function.empty()) {
                Function f = nullptr;
                HMODULE hModule = loadMathLibrary("plugins/func" + function + ".dll");
                f = (Function)GetProcAddress(hModule, "calculate");

                if (f) {
                    double a = s.top(); s.pop();
                    double result = f(a);
                    s.push(result);
                }

                function = "";
                FreeLibrary(hModule);
            }
        }
        else if (isOperator(c)) {
            double b = s.top(); s.pop();
            double a = s.top(); s.pop();
            double result;

            switch (c) {
            case '+': result = a + b; break;
            case '-': result = a - b; break;
            case '*': result = a * b; break;
            case '/': result = a / b; break;
            default: result = 0;
            }

            s.push(result);
        }
    }
    return s.top();
}

int main() {
    string expression;
    cout << "Enter expression: ";
    getline(cin, expression);

    string postfix = infixToPostfix(expression);

    double result = evaluatePostfix(postfix);
    cout << "Result: " << result << endl;

    return 0;
}
