#include <cstdint>

void doSomething ();

void foo (int32_t i)
{
    if (0 == i)
        doSomething ();
    else
        ;
    if (0 == i)
    {
        doSomething ();
    }
    else
    {
    }

    switch (i)
        case 0:
            doSomething ();
}

#include <cstdint>

void foo1 (int32_t i)
{
    if (i > 0)
    {
    }
    else if (i < 0)
    {
    }

    switch (i)
    {
        case 0:
            break;
        case 1:
            break;
    }
}

#include <cstdint>

void foo2 (int32_t i)
{
    switch (i)
    {
        case 0:
        case 1:
            ++i;
            break;
        case 2:
            ++i;
        default:
            break;
    }
}


#include <cstdint>

void doSomething ();
void doSomethingElse ();

void foo3 (int32_t i)
{
    switch (i)
    {
        case 0:
            doSomething ();
            break;
        default:
            doSomethingElse ();
            break;
    }

    if (0 == i)
    {
        doSomething ();
    }
    else
    {
        doSomethingElse ();
    }

    switch (i)
    {
        case 0:
            doSomething ();
            break;
        case 1:
        default:
            doSomethingElse ();
            break;
    }

    switch (i)
    {
        case 0:
        case 1:
            doSomething ();
            break;
        default:
            doSomethingElse ();
            break;
    }
}

void bar (bool b)
{
    switch (b)
    {
        case true:
            break;
        case false:
            break;
        default:
            break;
    }

    switch (b)
    {
        case true:
            break;
        case false:
        default:
            break;
    }
}