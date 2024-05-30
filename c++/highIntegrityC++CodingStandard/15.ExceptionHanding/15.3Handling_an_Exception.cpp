#include <cstdint>

class C
{
public:
    C ();

private:
    int32_t m_i;
};

C::C ()
try : m_i()
{
    ++m_i;
}
catch (...)
{
    --m_i;
}

bool f1 ();

void f2 ()
{
    throw;
}

void f3 ()
{
    try
    {
        if (f1 ())
        {
            throw float(0.0);
        }
        else
        {
            f2();
        }
    }
    catch (...)
    {
        f2();
    }
}

int main ()
{
    f3();
}
