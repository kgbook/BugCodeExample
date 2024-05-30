#include <cstdint>

int32_t f1 (int32_t v)
{
    int32_t i;

    if ((v > 0) && (v < 10))
    {
        i = v * v;
        --i;
        return i;
    }
    return 0;
}

int32_t f2 (int32_t v)
{
    if ((v > 0) && (v < 10))
    {
        int32_t i (v*v);
        --i;
        return i;
    }
    return 0;
}

int32_t f3 (int32_t max)
{
    int32_t i;
    for (i = 0; i < max; ++i)
    {
    }
    return i;
}

void f4 (int32_t max)
{
    for (int32_t i (0); i < max; ++i)
    {
    }
}
