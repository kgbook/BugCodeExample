#include <cstdint>

class A
{
public:
    ~A ();
};

class B : public A
{
};

class C
{
public:
    virtual ~C ();
};

class D : public C
{
};

class E
{
protected:
    ~E ();
};

class F : public E
{
};
