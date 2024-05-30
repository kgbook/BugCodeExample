#include <cstdio>
#include <cerrno>

bool foo ()
{
    std::puts ("hello world");
    return (0 == errno);
}
