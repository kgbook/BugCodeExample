
// a.h
#ifndef A_HEADER_FILE
#define A_HEADER_FILE

namespace {
    int v;
}

#endif // A_HEADER_FILE

// a.cpp
#include <iostream>

void f() {
    std::cout << "f(): " << v << std::endl;
    v = 42;
    // ...
}

// b.cpp
int * g() {
    std::cout << "g(): " << v << std::endl;
    v = 100;
}

int main() {
    extern void f();
    f(); // Prints v, sets it to 42
    g(); // Prints v, sets it to 100
    f();
    g();
}