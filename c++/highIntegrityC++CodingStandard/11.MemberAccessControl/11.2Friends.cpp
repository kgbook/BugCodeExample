class C
{
public:
    C & operator += (C const & other);

    friend C const operator + (C const &, C const & lhs);
};

class D
{
public:
    D & operator += (D const & other);
};

D const operator + (D const & rhs, D const & lhs)
{
    D result (rhs);
    result += (lhs);
    return result;
}

template <typename T, typename S>
void foo (T && t, S && s)
{
    t.foo ();
}

class A
{
private:
    void foo ();

    friend void foo(A &, A &);
    friend void foo(A &, A&&);
    friend void foo(A&&, A &);
    friend void foo(A&&, A&&);
};

int main ()
{
    A a;
    foo(a, a);
    foo(a, A());
    foo(A(), a);
    foo(A(), A());
}


# include <cstdint>
class B
{
public :
    B (B const &) = default ;
    B (B &&) = default ;
private :
    B ( int32_t );
    friend B createClassB ( int32_t );
};
B createClassB ( int32_t i)
{
    return B(i);
}
