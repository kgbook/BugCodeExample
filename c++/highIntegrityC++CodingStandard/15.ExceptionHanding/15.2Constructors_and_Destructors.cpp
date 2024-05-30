#include <stdexcept>
class B
{
public:
    ~B ()
    {
        throw std::runtime_error ("results in call to std::terminate");
    }
};

#include <cstdint>

class A
{
public:
    A () : m_p () {}

    ~A () noexcept(false)
    {
        if (nullptr == m_p)
        {
            throw std::runtime_error ("null pointer in A");
        }
    }

private:
    int32_t * m_p;
};

void foo (int32_t i)
{
    if (i < 0)
    {
        throw std::range_error ("i is negative");
    }
}

void bar ()
{
    try
    {
        A a;

        foo (-1);
    }
    catch (std::exception const & e)
    {
    }
}
