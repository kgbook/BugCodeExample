
// s.h
struct S {
    char c;
    int a;
};

void init_s(S &s);

// s.cpp

void init_s1(S &s) {
s.c = 'a';
s.a = 12;
}

// a.cpp

void f() {
    S s;
    init_s1(s);
}

const int n = 42;

int g(const int &lhs, const int &rhs);

inline int f(int k) {
    return g(k, n);
}