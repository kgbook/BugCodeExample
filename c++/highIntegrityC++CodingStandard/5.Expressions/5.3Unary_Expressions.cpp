#include <cstdint>

void foo ()
{
    uint32_t v;
    v = -1u;
    v = ~0u;
}

#include <cstdlib>

void foo1 ()
{
    int32_t * i = static_cast <int32_t *> (std::malloc (sizeof (int32_t)));
    std::free (i);
}

void bar ()
{
    int32_t * i = new int32_t;
    delete i;
}


void foo2 ()
{
    int32_t * i = new int32_t [10];
    delete i;
}

typedef int32_t ARRAY [10];

void bar1 ()
{
    int32_t * i = new ARRAY;
    delete i;
}