#include <cstddef>

class C
{
public:
    static void* operator new (std::size_t size);
    static void operator delete (void* ptr);

    void* operator new [] (std::size_t size);
};
