
#include <iostream>
#include <new>
#include <cstdlib>

struct S {
    S() { std::cout << "S::S()" << std::endl; }
    ~S() { std::cout << "S::~S()" << std::endl; }
};

void f() {
    alignas(struct S) char space[sizeof(struct S)];
    S *s1 = new (&space) S;

    // ...

    delete s1;
}

void f1() {
    int *i1, *i2;
    try {
        i1 = new int;
        i2 = new int;
    } catch (std::bad_alloc &) {
        delete i1;
        delete i2;
    }
}

struct P {};

class C {
    P *p;

public:
    C(P *p) : p(p) {}
    ~C() { delete p; }

    void f2() {}
};

void g(C c) {
    c.f2();
}

void h() {
    P *p = new P;
    C c(p);
    g(c);
}

void f3() {
    int *array = new int[10];
    // ...
    delete array;
}

void f4() {
    int *i = static_cast<int *>(std::malloc(sizeof(int)));
    // ...
    delete i;
}


struct S1 {
    static void *operator new(std::size_t size) noexcept(true) {
        return std::malloc(size);
    }

    static void operator delete(void *ptr) noexcept(true) {
        std::free(ptr);
    }
};

void f5() {
    S1 *s1 = new S1;
    ::delete s1;
}