#include <cstdint>

bool foo (int32_t a)
{

    return true;
}

void bar (int32_t b)
{
    if (foo (b))
    {
    }

    foo (b);
}


void foo (int32_t & a)
{
    a == 0;
}