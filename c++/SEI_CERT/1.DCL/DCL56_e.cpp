
#include <stdexcept>

int fact(int i) noexcept(false) {
if (i < 0) {
// Negative factorials are undefined.
throw std::domain_error("i must be >= 0");
}

static const int cache[] = {
        fact(0), fact(1), fact(2), fact(3), fact(4), fact(5),
        fact(6), fact(7), fact(8), fact(9), fact(10), fact(11),
        fact(12), fact(13), fact(14), fact(15), fact(16)
};

if (i < (sizeof(cache) / sizeof(int))) {
return cache[i];
}

return i > 0 ? i * fact(i - 1) : 1;
}

// file.h
#ifndef FILE_H
#define FILE_H

class Car {
    int numWheels;

public:
    Car() : numWheels(4) {}
    explicit Car(int numWheels) : numWheels(numWheels) {}

    int get_num_wheels() const { return numWheels; }
};
#endif // FILE_H

#include <iostream>

extern Car c;
int numWheels = c.get_num_wheels();

int main() {
    std::cout << numWheels << std::endl;
}

// file2.cpp


Car get_default_car() { return Car(6); }
Car c = get_default_car();