
#include <iostream>
#include <set>
#include <functional>

class S {
    int i, j;

public:
    S(int i, int j) : i(i), j(j) {}

    friend bool operator<(const S &lhs, const S &rhs) {
        return lhs.i < rhs.i && lhs.j < rhs.j;
    }

    friend std::ostream &operator<<(std::ostream &os, const S& o) {
        os << "i: " << o.i << ", j: " << o.j;
        return os;
    }
};

void f() {
    std::set<S> t{S(1, 1), S(1, 2), S(2, 1)};
    for (auto v : t) {
        std::cout << v << std::endl;
    }
}

void f1() {
    std::set<int, std::less_equal<int>> s{5, 10, 20};
    for (auto r = s.equal_range(10); r.first != r.second; ++r.first) {
        std::cout << *r.first << std::endl;
    }
}