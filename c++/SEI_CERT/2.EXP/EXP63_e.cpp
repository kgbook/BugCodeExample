
#include <iostream>
#include <string>

void g(std::string v) {
    std::cout << v << std::endl;
}

void f() {
    std::string s;
    for (unsigned i = 0; i < 10; ++i) {
        s.append(1, static_cast<char>('0' + i));
        g(std::move(s));
    }
}

#include <algorithm>
#include <vector>

void f(std::vector<int> &c) {
    std::remove(c.begin(), c.end(), 42);
    for (auto v : c) {
        std::cout << "Container element: " << v << std::endl;
    }
}