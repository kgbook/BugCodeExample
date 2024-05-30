#include <cstdint>

union U
{
    float f;
    int32_t i;
};

uint32_t foo (uint32_t u)
{
    --u;
    return u & 0xFFU;
}

bool cmp (int32_t * lhs, int32_t * rhs)
{
    return lhs < rhs;
}