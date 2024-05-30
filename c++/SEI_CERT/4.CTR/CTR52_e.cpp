
#include <algorithm>
#include <vector>

void f(const std::vector<int> &src) {
    std::vector<int> dest;
    std::copy(src.begin(), src.end(), dest.begin());

    std::vector<int> v;
    std::fill_n(v.begin(), 10, 0x42);
}
