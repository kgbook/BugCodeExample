#include <cstdint>
#include <cmath>

void foo (double d)
{
    int32_t i = d;
    i = d + 0.5;
    i = std::floor (d);
    i = std::floor (d + 0.5);
}
