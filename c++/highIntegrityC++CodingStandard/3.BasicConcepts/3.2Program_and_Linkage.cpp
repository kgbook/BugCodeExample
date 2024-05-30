#include <cstdint>

int32_t bar ()
{
    int32_t foo ();
    return foo ();
}

int32_t foo ()
{
}