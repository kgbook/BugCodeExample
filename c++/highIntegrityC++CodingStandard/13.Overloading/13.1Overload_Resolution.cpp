#include <cstdint>

class B
{
public:
    void foo (uint32_t);

    virtual void bar (uint32_t);
    virtual void bar (double);
};

class D : public B
{
public:
    void foo (double);

    void bar (double) override;
};

void f1 ()
{
    D d;
    d.foo (0U);
    B & b (d);
    b.foo (0U);

    d.bar (0U);
    b.bar (0U);
}

class E : public B
{
public:
    using B::foo;
    void foo (double);

    using B::bar;
    void bar (double) override;
};

void f2 ()
{
    E d;
    d.foo (0U);
    B & b (d);
    b.foo (0U);

    d.bar (0U);
    b.bar (0U);
}

namespace NS
{
    void foo (int32_t);
    struct A
    {
        int32_t a;
        int32_t b;
    };
}

using NS::foo;
using NS::A;

namespace NS
{
    void foo (uint32_t);
    int A;
}

uint32_t bar (uint32_t u)
{
    foo (u);
    return sizeof (A);
}


