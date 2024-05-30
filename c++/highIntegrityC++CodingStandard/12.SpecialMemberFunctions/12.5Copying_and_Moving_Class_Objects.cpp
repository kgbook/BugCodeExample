#include <cstdint>

class A0
{
public:
    A0();
    ~A0();

private:
    int32_t * m_i;
};

class A2
{
public:
    A2();
    ~A2();
    A2(A2 const &) = default;
    A2 & operator=(A2 const &) & = delete;

private:
    int32_t * m_i;
};

//X::X(X const & rhs)
//        : base1 (rhs)
//        , base2 (rhs )
//        , mbr1 (rhs . mbr1 )
//        , mbr2 (rhs . mbr2 )
//{
//}
//
//X::X(X && rhs)
//        : base1 (std :: move (rhs ))
//        , base2 (std :: move (rhs ))
//        , mbr1 (std :: move (rhs . mbr1 ))
//        , mbr2 (std :: move (rhs . mbr2 ))
//{
//}
//
//X::~X()
//{
//}

class A
{
public:
    ~A()
    {
    }

    A(A const & rhs)
            : mbr(rhs.mbr)
    {
    }

    A(A &&) = default;

private:
    int32_t mbr;
};

#include <utility>

class Base
{
public:
    Base ()
            : m_j (-1)
    {
    }

    Base (Base const & rhs)
            : m_j (rhs.m_j)
    {
    }

    Base (Base && rhs) noexcept
            : m_j (std::move (rhs.m_j))
    {
    }

private:
    int32_t m_j;
};

void foo ();

class Derived1 : public Base
{
public:
    Derived1 (Derived1 const & rhs)
            : Base (rhs)
            , m_i (rhs.m_i)
    {
        foo ();
    }

    Derived1 (Derived1 && rhs) noexcept
            : Base (std::move (rhs))
            , m_i (std::move (rhs.m_i))
    {
        foo ();
    }

private:
    int32_t m_i;
};

class Derived2 : public Base
{
public:
    Derived2 (Derived2 const & rhs)
            : Base (rhs)
            , m_i (rhs.m_i)
    {
    }

    Derived2 (Derived2 && rhs) noexcept
            : Base (std::move (rhs))
            , m_i (std::move (rhs.m_i))
    {
    }

private:
    int32_t m_i;
};

class B
{
public:
    B (B && rhs) noexcept
            : m_p (std::move (rhs.m_p))
    {
        rhs.m_p = 0;
    }

private:
    int32_t * m_p;
};

class A3
{
public:
    A3 (A3 && rhs)
            : m_a (std::move (rhs.m_a))
            , m_b ((rhs.m_b) ? std::move (rhs.m_b) : throw 0)
    {
    }

    A3& operator = (A3&&) noexcept;

private:
    B m_a;
    int32_t m_b;
};

class A1
{
public:
    A1(A1 && rhs) noexcept
            : m_p(std::move(rhs.m_p))
    {
    }

    ~A1()
    {
        delete m_p;
    }

private:
    int32_t * m_p;
};

class A4
{
public:
    A4(A4 && rhs) noexcept
            : m_p(std::move(rhs.m_p))
    {
        rhs.m_p = nullptr;
    }

    ~A4()
    {
        delete m_p;
    }

private:
    int32_t * m_p;
};
