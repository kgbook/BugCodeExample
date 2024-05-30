#include <cstdint>

//void bar (int8_t);
//
//void foo (const int32_t * p)
//{
//    int32_t * r = const_cast <int32_t *> (p);
//
//    int32_t i = reinterpret_cast <int32_t> (r);
//
//    i = (int32_t) r;
//
//    bar (int8_t (i));
//
//    bar (static_cast <int8_t> (i));
//}

//class Base
//{
//public:
//    virtual ~Base ();
//};
//
//class Derived : virtual public Base
//{
//public:
//    Derived (int32_t);
//};
//
//void foo (Base * base)
//{
//    Derived * d;
//    d = reinterpret_cast<Derived *> (base);
//    d = dynamic_cast<Derived *> (base);
//    auto d2 = Derived (0);
//}
//
//enum Colors { RED, GREEN = 2, BLUE };
//void bar()
//{
//    Colors color = static_cast  (1000);
//    if (1000 == color)
//    {
//    }
//}
//
//void foo()
//{
//    Colors color = static_cast  (1);
//    switch (color)
//    {
//        case RED:
//        case GREEN:
//        case BLUE:
//            break;
//        default:
//            break;
//    }
//}

class A
{
public:
    virtual void bar();
};

class B : public A
{
public:
    void bar() override;
    void foo();
};

void foo (A* a)
{
    (dynamic_cast<B*> (a))->foo();
    a->bar();
}