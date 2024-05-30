//

#include <random>
#include <iostream>
#include <ctime>

void f() {
    std::mt19937 engine;

    for (int i = 0; i < 10; ++i) {
        std::cout << engine() << ", ";
    }
}


void f1() {
    std::time_t t;
    std::mt19937 engine(std::time(&t));

    for (int i = 0; i < 10; ++i) {
        std::cout << engine() << ", ";
    }
}