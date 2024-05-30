#include <vector>
#include <cstdint>

void f(std::vector<int32_t> & v)
{
    for(std::vector<int32_t>::const_iterator iter = v.begin (), end = v.end ()
            ; iter != end
            ; ++iter)
    {
    }

    for(std::vector<int32_t>::const_iterator iter = v.cbegin (), end = v.cend ()
            ; iter != end
            ; ++iter)
    {
    }

    for(auto iter = v.cbegin (), end = v.cend ()
            ; iter != end
            ; ++iter)
    {
    }
}
