
// application.cpp
#include "library.h"

void f() {
    try {
        func();
    } catch(int &e) {
        // Handle error
    }
}