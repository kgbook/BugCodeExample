//#include <cstdint>
//// file.h
//template<typename T>
//void foo (T & t)
//{
//    ++t;
//}
//
//// file1.cpp
//void bar1 ()
//{
//    int32_t i = 3;
//    foo<int32_t> (i);
//}
//
//// file2.cpp
//template<>
//void foo<int32_t> (int32_t & t)
//{
//    --t;
//}
//
//void bar2 ()
//{
//    int32_t i = 3;
//    foo<int32_t> (i);
//}

#include <cstdint>

template<typename T>
void f1 (T);                  // #1

template<typename T>
void f1 (T*);                 // #2

template<>
void f1<int32_t*> (int32_t*); // #3

void f2 (int32_t * p)
{
    f1(p);                      // Calls #2
    f1<int32_t*>(p);            // Calls #3
}

#include <cstdint>

// t.h
template <typename T>
class A1 { };

template <typename T>
class A2 { };

extern template class A2<int32_t>;

// t.cpp
template class A1<int32_t>;
template class A2<int32_t>;