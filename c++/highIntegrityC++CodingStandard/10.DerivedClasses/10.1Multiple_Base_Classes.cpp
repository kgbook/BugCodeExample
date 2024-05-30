//class Base
//{
//public:
//    void foo ();
//};
//
//class Derived_left: public Base {};
//
//class Derived_right: public Base {};
//
//// @@- Non-Compliant: 2 subobjects for 'Base' -@@
//class Derived: public Derived_left, public Derived_right
//{
//};
//
//void test()
//{
//    Derived d;
//// ambiguous - Derived_left::Base::foo or Derived_right::Base::foo?
//    d.foo ();
//}

class Base1 {};

class Derived_left1: public virtual Base1 {};

class Derived_right1: public virtual Base1 {};

class Derived1: public Derived_left1, public Derived_right1
{
};
