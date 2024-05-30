#include <cstdint>

void foo (int32_t i)
{
    int32_t r = i << -1;
    r = -1 >> 1;
    r = ~0;

    uint32_t u = (-1) & 2u;
    u = (-1) | 1u;
    u = (-1) ^ 1u;
}