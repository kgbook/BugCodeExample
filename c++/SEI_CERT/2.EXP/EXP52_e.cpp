
#include <iostream>
void f() {
    int a = 14;
    int b = sizeof(a++);
    std::cout << a << ", " << b << std::endl;
}

void f1() {
    int i = 0;
    decltype(i++) h = 12;
    std::cout << i;
}

