#include <iostream>

class A
{
public:
    bool operator * (A const & other);
    bool operator == (A const & other);
};

A operator + (int32_t lhs, A const & rhs);
A operator + (A const & lhs, int32_t rhs);
std::ostream & operator << (std::ostream & o, A const & a);

#include <cstdint>

class Array
{
public:
    Array ()
    {
        for (int32_t i = 0; i < Max_Size; ++i )
        {
            m_x [i] = i;
        }
    }

    int32_t & operator [] (int32_t a)
    {
        return m_x[ a ];
    }

    int32_t operator [] (int32_t a) const
    {
        return m_x[ a ];
    }

private:
    static const int32_t Max_Size = 10;
    int32_t m_x [Max_Size];
};

void foo ()
{
    Array a;
    int32_t i = a [3];
    a [3] = 33;

    Array const ca;
    i = ca [3];
//    ca [3] = 33;
}