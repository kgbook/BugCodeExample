#include <cstdint>

class A
{
public:
    virtual ~A () = 0;
    virtual void foo () = 0;
};

class B
{
public:
    virtual ~B () = 0;
    virtual void bar () = 0;
};

class C
{
public:
    C ();
    void foo ();
    virtual ~C ();

private:
    int32_t m_i;
};

class D: public A, public B, public C
{
public:
    ~ D();
};

class E
{
public:
    E ();
};

class F : public E, public D
{
};