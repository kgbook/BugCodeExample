
#include <algorithm>
#include <cstddef>
#include <memory>
#include <type_traits>
#include <functional>

class S {
    int i;

public:
    S() : i(0) {}
    S(int i) : i(i) {}
    S(const S&) = default;
    S& operator=(const S&) = default;
};

template <typename Iter>
void f(Iter i, Iter e) {

    static_assert(std::is_same<typename std::iterator_traits<Iter>::value_type, S>::value,
                  "Expecting iterators over type S");
    ptrdiff_t count = std::distance(i, e);
    if (!count) {
        return;
    }

    // Get some temporary memory.
    auto p = std::get_temporary_buffer<S>(count);
    if (p.second < count) {
        // Handle error; memory wasn't allocated, or insufficient memory was allocated.
        return;
    }
    S *vals = p.first;

    // Copy the values into the memory.
    std::copy(i, e, vals);

    // ...

    // Return the temporary memory.
    std::return_temporary_buffer(vals);
}

struct B {};

struct D1 : virtual B {};
struct D2 : virtual B {};

struct S1 : D1, D2 {};

void f1(const B *b) {}

int * g() {
    S1 *s = reinterpret_cast<S1 *>(new S);
    // Use s
    delete s;

    f1(s);
}

int *g2() {
    int i = 12;
    return &i;
}

void h2(int *i);

void f2() {
    int *i = g();
    h2(i);
}

void f3() {
    auto l = [](const int &j) { return j; };
    std::function<const int&(const int &)> fn(l);

    int i = 42;
    int j = fn(i);
}
