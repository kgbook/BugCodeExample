#include <iterator>
#include <cstdint>

void bar ()
{
    uint32_t array[] = { 0, 1, 2, 3, 4, 5, 6 };
    uint32_t sum = 0;

    for (uint32_t * p = std::begin (array); p != std::end (array); ++p)
    {
        sum += *p;
    }

    sum = 0;
    for (uint32_t v : array )
    {
        sum += v;
    }

    for (size_t i = 0; i != (sizeof(array)/sizeof(*array)); ++i)
    {
        if ((i % 2) == 0)
        {
            sum += array[i];
        }
    }

}

int32_t foo ();

void bar (int32_t max)
{
    for (int32_t i (0), j (foo ()) ; (i < max) && (j > 0); ++i, j = foo ())
    {
    }

    bool keepGoing (true);
    for (int32_t i (0) ; keepGoing && (i < max); ++i)
    {
        keepGoing = foo () > 0;
    }

    for (int32_t i (0) ; i < max; ++i)
    {
        if (foo () <= 0)
        {
            break;
        }
    }
}

void foo1()
{
    for ( int32_t i (0); i != 10; ++i )
    {
        if ( 0 == i % 3 )
        {
            ++i;
        }
    }
}

bool foo2 ();

void bar1 (int32_t max)
{
    for (int i (0) ; i < max; )
    {
        if (foo ())
        {
            ++i;
        }
    }
}