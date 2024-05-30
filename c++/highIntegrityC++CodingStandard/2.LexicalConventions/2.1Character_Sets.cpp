#include <cstdint>

void do_something(){}
void do_something_else(){}

void foo (int32_t i)
{
    if (i)
        do_something ();
    do_something_else ();
}

void bar (int32_t i)
{
    if (i)
        do_something ();
    do_something_else ();
}