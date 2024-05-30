#include <iostream>
#include <cstdint>

namespace
{
    const int32_t MAX_ITERATIONS (10);
    const char * const LOOP_ITER_S ("iter ");
    const char SEP_C (':');
}
void foo ()
{
    for (int32_t i = 0 ; i < 10; ++i)
    {
        std::cout << "iter " << i << ':' << std::endl;
    }

    for (int32_t i = 0 ; i < MAX_ITERATIONS; ++i)
    {
        std::cout << LOOP_ITER_S << i << SEP_C << std::endl;
    }
}

int32_t foo (int32_t i, int32_t j)
{
    int32_t k = ++i + ++j;
    k = ++i;
    ++i;
    ++j;
    k = i + j;

    k = i + ++i;

    if (k = 0)
    {
    }

    return i, j;
}

int32_t foo1 (int32_t i, int32_t j)
{
    int32_t k;
    k = i + j;
    int32_t r = i + j * k;
    r = i + j + k;

    if ((i != 0) && (j != 0) && (k != 0))
    {
    }

    if ((i != 0) && (j != 0) || (k != 0))
    {
    }

    if (((i != 0) && (j != 0)) || (k != 0))
    {
    }

    return i + j + k;
}

#include <vector>
#include <algorithm>
void foo (std::vector<size_t> const & v)
{
    size_t sum = 0;
    std::for_each(v.cbegin ()
            , v.cend ()
            , [&](size_t s) { sum += s; } );

    sum = 0;
    std::for_each(v.cbegin ()
            , v.cend ()
            , [&sum](size_t s) { sum += s; } );
}

void foo1 ()
{
    const size_t N = 10;
    static int32_t j = 0;
    []( size_t s)
    {
        int32_t array [N];
        ++j; // Compliant
    };
}

int32_t i;
int32_t j;
void foo2 ()
{
    int32_t a[]    { ++i, ++j  } ;
    []    { ++i, ++j ;} ;
    [] () { ++i, ++j ;} ;
}

#include <typeinfo>

bool doSideAffect();

class C
{
public:
    virtual ~C();
};

C& foo3();

void foo3( bool condition )
{
    {}

    if (true || doSideAffect ())
    {}

    sizeof (doSideAffect());
    typeid (doSideAffect());
    typeid (foo3());
}

#include <mutex>
#include <condition_variable>

std::mutex mut;
std::condition_variable cv;

int32_t i1;

bool sideEffects()
{
    ++i1;
    return (i1 > 10);
}

void threadX()
{
    i1 = 0;
    std::unique_lock<std::mutex> guard(mut);
    cv.wait(guard, sideEffects);
}
