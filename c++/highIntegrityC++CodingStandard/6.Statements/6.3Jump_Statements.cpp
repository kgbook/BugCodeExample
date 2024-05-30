#include <cstdint>

void f1 (int32_t i)
{
    start:
    ++i;
    if (i < 10)
    {
        goto start;
    }
}

void f2 (int32_t i)
{
    do
    {
        ++i;
    } while (i < 10);
}


bool f3 (int (&array)[10][10])
{
    for (int j1 = 0; j1 < 10; ++j1)
    {
        for (int j2 = 0; j2 < 10; ++j2)
        {
            if (array[j1][j2] == 0)
            {
                goto finished;
            }

        }
    }

    finished:
    return true;
}

void f4 (int32_t i)
{
    switch (i)
    {
        case 0:
            break;
        default:
            if (i < 0)
            {
                case 1:
                    break;
            }
            break;
    }
}

int32_t foo (bool b)
{
    if (b)
    {
        return -1;
    }
}