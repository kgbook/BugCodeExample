#include <cstdint>

namespace NS
{
    class C
    {
    public:
        C (int32_t)
        {
            m_i = (m_i + m_i + m_i + m_i + m_i + m_i + m_i);
            m_i = (m_i + m_i + m_i + m_i + m_i + m_i + m_i);
            m_i = (m_i + m_i + m_i + m_i + m_i + m_i + m_i);
        }
        int32_t foo ()
        {
            m_i = (m_i + m_i + m_i + m_i + m_i + m_i + m_i);
            m_i = (m_i + m_i + m_i + m_i + m_i + m_i + m_i);
        }

    private:
        int m_i;
    };

// @@- Non-Compliant: Cost greater than 32 -@@
    inline int32_t foo (int32_t i)
    {
        C c (i);
        return c.foo ();
    }
}


//class Length;
//class Time;
//class Velocity;
//class Acceleration;
//
//const Velocity operator / (Length, Time);
//const Velocity operator * (Acceleration, Time);
//const Velocity operator * (Time, Acceleration);
//
//typedef char BYTE;
//
//BYTE foo (BYTE v)
//{
//    return 2 * v;
//}
//
//typedef signed char int8_t;
//typedef short       int16_t;
//typedef int         int32_t;
//typedef long long   int64_t;
//
//#include <cstdint>
//
//void foo ()
//{
//    auto a (0);
//    auto b (0L);
//    auto c (0U);
//    auto d (static_cast (0));
//    int32_t e (0);
//}
//
//
//class A
//{
//public :
//    A operator ++( int );
//    A operator --( int );
//};
//int main ()
//{
//}