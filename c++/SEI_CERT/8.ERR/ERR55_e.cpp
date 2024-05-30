
#include <vector>
#include <exception>

void f(std::vector<int> &v, size_t s) noexcept(true) {
    v.resize(s); // May throw
}

class Exception1 : public std::exception {};
class Exception2 : public std::exception {};

void foo() {
    throw Exception2{}; // Okay because foo() promises nothing about exceptions
}

void bar() throw (Exception1) {
    foo();    // Bad because foo() can throw Exception2
}