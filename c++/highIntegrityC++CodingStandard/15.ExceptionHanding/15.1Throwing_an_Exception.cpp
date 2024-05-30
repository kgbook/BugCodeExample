#include <cstdint>
#include <stdexcept>
#include <iostream>

int foo ();

void bar ()
{
    try
    {
        if (0 == foo ())
        {
            throw -1;
        }
    }
    catch (int32_t e)
    {
    }

    try
    {
        if (0 == foo ())
        {
            throw std::runtime_error ("unexpected condition");
        }
    }
    catch (std::exception const & e)
    {
        std::cerr << e.what ();
    }
}

#include <exception>

class MyException : public std::exception
{
};

void f1 ()
{
    MyException myExcp;
}

void f2 ()
{
    MyException myExcp;
    throw myExcp;
}