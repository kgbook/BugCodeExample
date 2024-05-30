#include <cstdint>

void foo (int32_t a, bool b, bool c)
{
    if (a > 0)                            // 1
    {
        if (b)                                // 2
        {
        }

        for (int32_t i (0); i < a; ++i)       // 3
        {
        }

        if (c)                                // 4
        {
        }
    }
    else if (0 == a)                        // 5
    {
        if (b)                                // 6
        {
        }

        if (c)                                // 7
        {
        }
    }
    else
    {
        if (c)                                // 8
        {
        }

        for (int32_t i (-a - 1); i >= 0; --i) // 9
        {
        }

        if (b)                                // 10
        {
        }
    }
}


bool foo ();

void bar ()
{
    if (foo ()) // 2 paths
    {
    }
    if (foo ()) // 4 paths
    {
    }
    if (foo ()) // 8 paths
    {
    }
    if (foo ()) // 16 paths
    {
    }
    if (foo ()) // 32 paths
    {
    }
    if (foo ()) // 64 paths
    {
    }
    if (foo ()) // 128 paths
    {
    }
    if (foo ())
    {
    }
}

void foo (int32_t i, int32_t j = 0);

void bar (int32_t i, int32_t j);
inline void bar (int32_t i)
{
    bar (i, 0);
}