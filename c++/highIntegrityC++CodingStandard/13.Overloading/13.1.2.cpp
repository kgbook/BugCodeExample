#include <cstdint>

template<typename T>
void f11 (T&&t);
void f21 ()
{
    int32_t i;
    f11(i);
    f11(0);
}

#include <cstdint>

template <typename T> void f1 (T&&t);
void f1 (int&&t);

void f2()
{
    int32_t i = 0;
    f1(i);
    f1(+i);
    f1(0);
    f1(0U);
}