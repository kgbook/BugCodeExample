
#include <memory>

void f() {
    int *i = new int;
    std::shared_ptr<int> p1(i);
    std::shared_ptr<int> p2(i);
}

struct B {
    virtual ~B() = default; // Polymorphic object
    // ...
};
struct D : B {};

void g(std::shared_ptr<D> derived);

void f1() {
    std::shared_ptr<B> poly(new D);
    // ...
    g(std::shared_ptr<D>(dynamic_cast<D *>(poly.get())));
    // Any use of poly will now result in accessing freed memory.
}

struct S {
    std::shared_ptr<S> g() { return std::shared_ptr<S>(this); }
};

void f2() {
    std::shared_ptr<S> s1 = std::make_shared<S>();
    // ...
    std::shared_ptr<S> s2 = s1->g();
}