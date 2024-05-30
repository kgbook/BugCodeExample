#include <cstdint>

class A
{
public:
    virtual ~A () = 0;
    A& operator = (A const &) &;
};

class AA : public A
{
};

void foo()
{
    AA obj1;
    AA obj2;

    A* ptr1 = &obj1;
    A* ptr2 = &obj2;

    *ptr1 = *ptr2;
}

class B
{
public:
    virtual ~B () = 0;

protected:
    B& operator = (B const &) &;
};

class C
{
public:
    virtual ~C () = 0;

protected:
    C& operator = (C const &) & = default;
};

class D
{
public:
    virtual ~D () = 0;
    D& operator = (D const &) & = delete;
};