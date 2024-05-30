
#include <iostream>
#include <vector>
#include <iterator>
#include <functional>

template <typename Ty>
bool in_range(const Ty *test, const Ty *r, size_t n) {
    return 0 < (test - r) && (test - r) < (std::ptrdiff_t)n;
}

void f() {
    double foo[10];
    double *x = &foo[0];
    double bar;
    std::cout << std::boolalpha << in_range(&bar, x, 10);
}
template <typename Ty>
bool in_range1(const Ty *test, const Ty *r, size_t n) {
    return test >= r && test < (r + n);
}

void f1() {
    double foo[10];
    double *x = &foo[0];
    double bar;
    std::cout << std::boolalpha << in_range1(&bar, x, 10);
}

template <typename RandIter>
bool in_range_impl(RandIter test, RandIter r_begin, RandIter r_end, std::random_access_iterator_tag) {
    return test >= r_begin && test < r_end;
}

template <typename Iter>
bool in_range2(Iter test, Iter r_begin, Iter r_end) {
    typename std::iterator_traits<Iter>::iterator_category cat;
    return in_range_impl(test, r_begin, r_end, cat);
}

void f2() {
    std::vector<double> foo(10);
    std::vector<double> bar(1);
    std::cout << std::boolalpha << in_range2(bar.begin(), foo.begin(), foo.end());
}

template <typename Ty>
bool in_range3(const Ty *test, const Ty *r, size_t n) {
    std::less<const Ty *> less;
    return !less(test, r) && less(test, r + n);
}

void f3() {
    double foo[10];
    double *x = &foo[0];
    double bar;
    std::cout << std::boolalpha << in_range3(&bar, x, 10);
}