#include <typeinfo>
class A
{
public:
    virtual void foo ();
    virtual void bar ();
};

class B : public A
{
public:
    B();
    ~B();

    void foo () override;
};

class C : public B
{
public:
    void foo () override;
    void bar () override;
};

B::B()
{
    foo ();
    B::foo ();
    typeid (*this);
}

B::~B()
{
    bar ();
    A::bar ();
    dynamic_cast <A*> (this);
    dynamic_cast <C*> (this);
}

void foo ()
{
    C c;
}
