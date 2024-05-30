#include <cassert>
#include <cstdint>


void foo (int32_t* i)
{
    int32_t k = *i;

    assert (i != nullptr);
    k = *i;

    int32_t a [10];
    for (int32_t i (0); i < 10; ++i)
    {
        a [i] = i;
    }

    int32_t * p = & (a [10]);
    k = *p;
}

int32_t a (int32_t);
int32_t b (int32_t);
int32_t c (int32_t);
int32_t d (int32_t);
int32_t e (int32_t);
int32_t f (int32_t);
int32_t g (int32_t);
int32_t h (int32_t);

int32_t foo (int32_t v)
{
    if (a (v))
    {
        return e (v);
    }
    else if (b (v))
    {
        return foo (f (v));
    }
    else if (c (v))
    {
        return g (v);
    }
    else if (d (v))
    {
        return foo (h (v));
    }
}

int32_t bar (int32_t v)
{
    for (;;)
    {
        if (a (v))
        {
            v = e (v);
            break;
        }
        else if (b (v))
        {
            v = f (v);
        }
        else if (c (v))
        {
            v = g (v);
            break;
        }
        else if (d (v))
        {
            v = h (v);
        }
    }
    return v;
}