#include <mutex>
#include <cstdint>

std::mutex mut;
int32_t i;

void f2(int32_t j);

void f1(int32_t j)
{
    std::lock_guard<std::mutex> hold(mut);
    if (j)
    {
        f2(j);
    }
    ++i;
}

void f2(int32_t j)
{
    if (! j)
    {
        std::lock_guard<std::mutex> hold(mut);
        ++i;
    }
}