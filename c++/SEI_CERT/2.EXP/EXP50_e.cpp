
#include <iostream>

void f(int i, const int *b) {
    int a = i + b[++i];
    // ...
}

extern void func(int i, int j);

void f1(int i) {
    func(i++, i);
}



void f2(int i) {
    std::cout << i++ << i << std::endl;
}

extern void c(int i, int j);
int glob;

int a() {
    return glob + 10;
}

int b() {
    glob = 42;
    return glob;
}

void f3() {
    c(a(), b());
}
