//#include <cstdint>
//
//class A {
//public:
//    virtual void f(int64_t);
//};
//
//class B : public A {
//public:
//    void f(int32_t) override;
//};

#include <cstdint>

class C {
public:
    virtual void f1(int32_t);
};

class D : public C {
public:
    virtual void f1(int32_t);
};

void f1(C & c)
{
    c.f1(0);
}

class E {
public:
    virtual void f2(int64_t);
};

class F : public E {
public:
    virtual void f2(int32_t);
};

void f2(E & e)
{
    e.f2(0);
}