
#include <new>

struct S {
    S ();
    ~S ();
};

void f() {
    const unsigned N = 32;
    alignas(S) unsigned char buffer[sizeof(S) * N];
    S *sp = ::new (buffer) S[N];

    // ...
    // Destroy elements of the array.
    for (std::size_t i = 0; i != N; ++i) {
        sp[i].~S();
    }
}

void f1() {
    short s;
    long *lp = ::new (&s) long;
}

void f2() {
    char c; // Used elsewhere in the function
    unsigned char buffer[sizeof(long)];
    long *lp = ::new (buffer) long;

    // ...
}