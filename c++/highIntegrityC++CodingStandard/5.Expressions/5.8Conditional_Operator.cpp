#include <cstdint>

void foo (int32_t i, int32_t j)
{
    int32_t k;
    k = (j != 0) ? 1 : 0;

    k = (i != 0) ? ((j != 0) ? 1 : 0) : 0;

    k = i + ((j != 0) ? 1 : 0);
}
