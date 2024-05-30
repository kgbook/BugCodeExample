
#include <iostream>

class Handle {
    class Body *impl;  // Declaration of a pointer to an incomplete class
public:
    ~Handle() { delete impl; } // Deletion of pointer to an incomplete class
    // ...
};

// File1.h
class B {
protected:
    double d;
public:
    B() : d(1.0) {}
};

// File2.h
void g(class D *);
class B *get_d(); // Returns a pointer to a D object

void f() {
    B *v = get_d();
    g(reinterpret_cast<class D *>(v));
}

class Hah {
protected:
    short s;
public:
    Hah() : s(12) {}
};

class D : public Hah, public B {
    float f;
public:
    D() : Hah(), B(), f(1.2f) {}
    void do_something() { std::cout << "f: " << f << ", d: " << d << ", s: " << s << std::endl; }
};

void g(D *d) {
    d->do_something();
}

B *get_d() {
    return new D;
}