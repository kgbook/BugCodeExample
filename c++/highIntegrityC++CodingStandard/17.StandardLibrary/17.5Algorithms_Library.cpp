#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdint>

int main ()
{
    std::vector<int32_t> v1 = { 0, 0, 1, 1, 2, 2, 3, 3, 4, 4 };
    std::unique(v1.begin(), v1.end ());

// The possible contents of the vector are:
// { 0, 1, 2, 3, 4, 2, 3, 3, 4, 4 };

    std::vector<int32_t> v2 = { 0, 0, 1, 1, 2, 2, 3, 3, 4, 4 };
    v2.erase (std::unique(v2.begin(), v2.end ()), v2.end ());
}
