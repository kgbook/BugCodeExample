#include <cstdint>

void foo ()
{
    uint32_t u (0);

    u += 2;
    u += 2U;
}

#include <climits>
#include <stdexcept>
#include <cstdint>

uint32_t inv_mult (uint32_t a, uint32_t b)
{
    return ((0 == a) || (0 == b)) ? UINT_MAX
                                  : (1000 / (a * b));
}

void foo1 ()
{
    inv_mult (0x10000u, 0x10000u);
}

uint32_t safe_inv_mult (uint32_t a, uint32_t b)
{
    if ((b != 0) && (a > (UINT_MAX / b)))
    {
        throw std::range_error ("overflow");
    }
    return ((0 == a) || (0 == b)) ? UINT_MAX
                                  : (1000 / (a * b));
}


#include <cstdint>

void foo (uint8_t u)
{
    uint32_t v = u >> 8U;
    v <<= 32U;
    v = 0xF1234567U << 1;
}

#include <cstdint>

int32_t foo2 ();

void bar (int32_t i)
{
    if (i)
    {
    }

    if (i != 0)
    {
    }

    for (int32_t j (10); j ; --j)
    {
    }

    while (int32_t j = foo2 ())
    {
    }
}