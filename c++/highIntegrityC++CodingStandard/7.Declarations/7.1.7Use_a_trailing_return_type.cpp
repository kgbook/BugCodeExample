template <typename T>
class A
{
    typedef T TYPE;
    TYPE f1(TYPE);
    TYPE f2(TYPE);
};

template <typename T>
typename A<T>::TYPE A<T>::f1 (TYPE)
{
}

template <typename T>
auto  A<T>::f2 (TYPE) -> TYPE
{
}

#include <cstdint>

int32_t foo();
int main ()
{
    int32_t i = foo();
}

int32_t foo();
int main1 ()
{
    auto i = foo();
}

#include <vector>
#include <algorithm>
#include <cstdint>

bool f(std::vector<int32_t> const & v1, std::vector<int32_t> & v2)
{
    v2.reserve(v1.size());
    std::transform (v1.cbegin ()
            , v1.cend ()
            , v2.begin()
            , [](std::vector<int32_t>::value_type i) -> int32_t
                    { return i + 10; } );

    std::transform (v1.cbegin ()
            , v1.cend ()
            , v2.begin()
            , [](std::vector<int32_t>::value_type i)
                    { return i + 10; } );
}

#include <cassert>

template <typename T, int N>
bool f(T i)
{
    assert((sizeof(T)*8) == N
           && "Expect that the size of the type matches the value specified by N");

    static_assert((sizeof(T)*8) == N
            , "Expect that the size of the type matches the value specified by N");
}