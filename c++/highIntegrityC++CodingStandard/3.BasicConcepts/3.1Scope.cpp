#include <cstdint>

void foo (int32_t);

int32_t i;

void bar (int32_t max)
{
    for (int32_t i (0); i < max; ++i)
    {
        for (int32_t i (0); i < max; ++i)
        {

            foo (::i);
            foo (i);
        }
    }
}

// valid C++
class C;
int32_t C;