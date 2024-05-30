
#include <cstdarg>

extern "C" void f(float a, ...) {
    va_list list;
    va_start(list, a);
    // ...
    va_end(list);
}

#include <iostream>

extern "C" void f1(int &a, ...) {
    va_list list;
    va_start(list, a);
    if (a) {
        std::cout << a << ", " << va_arg(list, int);
        a = 100; // Assign something to a for the caller
    }
    va_end(list);
}

#include <string>

extern "C" void f2(std::string s, ...) {
    va_list list;
    va_start(list, s);
    std::cout << s << ", " << va_arg(list, int);
    va_end(list);
}