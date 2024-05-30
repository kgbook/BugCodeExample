void foo (bool b)
{
    ++b;
}

void bar (bool b)
{
    b = true;
}

#include <cstdint>

int32_t square (register int32_t a)
{
    return a * a;
}

#include <string.h>
#include <cstring>

int32_t foo (const char * s)
{
    return 2 * std::strlen (s);
}


#include <memory>

void foo ()
{
    std::auto_ptr<int32_t> p1 (new int32_t(0));
    std::unique_ptr<int32_t> p2 (new int32_t(0));
}
