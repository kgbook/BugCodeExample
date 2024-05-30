#include <cstdint>
#include <iostream>

class A
{
public:
    A();
// ...
};

std::ostream operator<<(std::ostream &, A const &);

int main ()
{
    int32_t i;
    A a;

    std::cout << i << std::endl;
    std::cout << a << std::endl;
}

#include <vector>

int main1 ()
{
    std::vector<int32_t> v1;
    std::vector<int32_t> v2;

    std::vector<int32_t> v3 (std::move (v1));
    std::vector<int32_t> v4 (std::move (v2));

    v1.empty ();

    v2 = v4;
    v2.empty ();
}

struct S
{
    int32_t i;
    int32_t j;
    int32_t k;
};

struct T
{
    struct S s;
    int32_t a[5];
};

void foo ()
{
    S s1 = {0, 1};
    S s2 = {0, 1, 2};

    T t1 = {0, 1, 2, 3, 4, 5, 6, 7};
    T t2 = {0, 1, 2, {3, 4, 5, 6, 7}};
    T t3 = {{0, 1, 2}, {3, 4, 5, 6, 7}};
}