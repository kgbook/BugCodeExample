#include <cstdint>
#include <utility>

template <typename T> void f1 (T&&);
template <typename T> void f1 (T const &);

void f2 (int32_t const & i)
{
    f1(i);
    f1(std::move(i));
}

template <typename ...T>
void f1 (T...t);

template <typename T1, typename T2>
void f2 (T1 && t1, T2 & t2)
{
    f1( std::forward<T1>(t1) );
    f1( std::forward<T2>(t2) );
    f1( std::move(t1) );
    f1( std::move(t2) );
}
void f3()
{
    int32_t i;
    f2(0, i);
}

template <typename T1, typename T2>
void bar (T1 const & t1, T2 & t2);

template <typename T1, typename T2>
void foo (T1 && t1, T2 && t2)
{
//    bar (std::forward<T1> (t1), std::forward (t2));
    ++t2;
}

int main ()
{
    int32_t i = 0;
    foo (0, i);
}

#include <memory>
#include <array>
#include <vector>

typedef std::vector<int32_t> int_seq;

void foo ()
{
    std::unique_ptr<int32_t[]> oa_1 (new int32_t[10]);

    std::shared_ptr<int32_t> ob_1 (new int32_t[10]
            , std::default_delete<int32_t[]>());

    std::array<int32_t, 10> oa_2;

    std::shared_ptr< int_seq > ob_2 (std::make_shared<int_seq>( 10
            , int32_t() ));
}

//#include <array%gt;
void f1(std::array<int32_t, 10> const &);
void f2(std::array<int32_t, 10> &&);