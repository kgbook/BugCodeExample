#include <cstdint>

class A
{
public:
    A()
            : m_i1(1)
            , m_i2(1)
    {
    }

private:
    int m_i1;
    int m_i2 = 0;
    int m_i3 = 0;
};


# include <cstdint>
class B
{
public :
    B(B const & rhs)
            : m_i1 (rhs. m_i1 )
            , m_i2 (rhs . m_i2 )
    {
    }
private :
    int32_t m_i1 ;
    int32_t m_i2 = 0;
};
