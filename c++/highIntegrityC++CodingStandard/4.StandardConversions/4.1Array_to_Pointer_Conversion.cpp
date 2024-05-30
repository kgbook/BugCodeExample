#include <cstdint>
#include <array>

void f (int32_t a[10]);
void g (int32_t a[]);
void h (int32_t * a);
void i (int32_t (&a) [10]);
void j (std::array<int32_t, 10> & a);

void foo ()
{
    int32_t a1 [10];
    std::array<int32_t, 10> a2;

    f(a1);
    g(a1);
    h(a1);
    i(a1);
    j(a2);
}