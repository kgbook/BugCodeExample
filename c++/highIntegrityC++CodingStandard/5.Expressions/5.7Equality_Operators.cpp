#include <cmath>
#include <limits>

bool isEqual( const double a, const double b )
{
    const double scale = ( std::fabs( a ) + std::fabs( b ) ) / 2.0;

    return std::fabs( a - b ) <= ( std::numeric_limits<double>::epsilon()
                                   * scale );
}

void foo( double f )
{
    if (3.142 == f)
    {}

    if (isEqual (f, 3.142))
    {}
}

class A
{
public:
    void f1();
    void f2();
    virtual void f3();
};

void foo( )
{
    if (&A::f1 == &A::f2);
    if (&A::f1 == nullptr);
    if (&A::f3 == &A::f2);
    if (&A::f3 == nullptr);
}