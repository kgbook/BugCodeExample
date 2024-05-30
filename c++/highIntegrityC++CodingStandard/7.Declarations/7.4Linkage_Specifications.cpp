static void foo ();

namespace
{
    void bar ();
}

#include <cstdint>

struct S1
{
    int32_t i;
    int32_t j;
};

struct S2
{
    int16_t i;
    int32_t j;
};

// file1.cpp
extern void foo ();

// file2.cpp
extern void foo ()
{
// ...
}
