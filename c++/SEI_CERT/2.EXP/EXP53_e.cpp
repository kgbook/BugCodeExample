
#include <iostream>

void f() {
    int i0;
    std::cout << i0;
    int *i1 = new int;
    std::cout << i1 << ", " << *i1;

}

class S {
    int c;

public:
    int f(int i2) const { return i2 + c; }
};

void f1() {
    S s;
    int i2 = s.f(10);
}
