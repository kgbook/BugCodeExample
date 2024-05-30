#include <cstdint>
#include <cassert>

int32_t doDivide(int32_t number, int32_t divisor)
{
    assert (0 != divisor);
    return number / divisor;
}