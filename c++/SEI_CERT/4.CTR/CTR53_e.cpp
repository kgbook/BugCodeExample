
#include <algorithm>
#include <iostream>
#include <vector>

void f(const std::vector<int> &c) {
    std::for_each(c.end(), c.begin(), [](int i) { std::cout << i; });
    std::vector<int>::const_iterator e;
    std::for_each(c.begin(), e, [](int i) { std::cout << i; });
}
