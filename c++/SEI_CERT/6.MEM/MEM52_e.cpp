
#include <cstring>

void f(const int *array, std::size_t size) noexcept {
    int *copy = new int[size];
    std::memcpy(copy, array, size * sizeof(*copy));
    // ...
    delete [] copy;
}

struct A { /* ... */ };
struct B { /* ... */ };

void g(A *, B *);
void f() {
    g(new A, new B);
}