
#include <iostream>

class S1 {
    int cachedValue;

    int compute_value() const;  // expensive
public:
    S1() : cachedValue(0) {}

    // ...
    int get_value() const {
        if (!cachedValue) {
            const_cast<S1 *>(this)->cachedValue = compute_value();
        }
        return cachedValue;
    }
};

void f1() {
    const S1 s1;
    std::cout << s1.get_value() << std::endl;
}
void g(const int &ci) {
    int &ir = const_cast<int &>(ci);
    ir = 42;
}

void f2() {
    const int i = 4;
    g(i);
}

struct S {
    int i;

    S(int i) : i(i) {}
};

void g(S &s) {
    std::cout << s.i << std::endl;
}

void f3() {
    volatile S s(12);
    g(const_cast<S &>(s));
}
