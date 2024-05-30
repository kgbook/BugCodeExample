#include <utility>
#include <cstdint>

class A1
{
public:
    A1(A1 const & rhs)
            : m_p1(new int32_t (*rhs.m_p1))
            , m_p2(new int32_t (*rhs.m_p2))
    {
    }

    A1(A1 && rhs) noexcept
            : m_p1(std::move (rhs.m_p1))
            , m_p2(std::move (rhs.m_p2))
    {
        rhs.m_p1 = nullptr;
        rhs.m_p2 = nullptr;
    }

    ~A1()
    {
        delete m_p1;
        delete m_p2;
    }

    A1 & operator=(A1 const & rhs) &
    {
        if (this != &rhs)
        {
            m_p1 = new int32_t (*rhs.m_p1);

            m_p2 = new int32_t (*rhs.m_p2);
        }
        return *this;
    }

    A1 & operator=(A1 && rhs) & noexcept
    {
        if (this != &rhs)
        {
            m_p1 = std::move (rhs.m_p1);
            m_p2 = std::move (rhs.m_p2);
            rhs.m_p1 = nullptr;
            rhs.m_p2 = nullptr;
        }
        return *this;
    }

private:
    int32_t * m_p1;
    int32_t * m_p2;
};

class A2
{
public:
    A2(A2 const & rhs)
            : m_p1(new int32_t (*rhs.m_p1))
            , m_p2(new int32_t (*rhs.m_p2))
    {
    }

    A2(A2 && rhs) noexcept
            : m_p1(std::move (rhs.m_p1))
            , m_p2(std::move (rhs.m_p2))
    {
        rhs.m_p1 = nullptr;
        rhs.m_p2 = nullptr;
    }

    ~A2()
    {
        delete m_p1;
        delete m_p2;
    }

    A2 & operator=(A2 rhs) &
    {
        swap (*this, rhs);
        return *this;
    }

    A2 & operator=(A2 && rhs) & noexcept
    {
        A2 tmp (std::move (rhs));
        swap (*this, tmp);
        return *this;
    }

    void swap(A2 & lhs, A2 & rhs) noexcept
    {
        std::swap (lhs.m_p1, rhs.m_p1);
        std::swap (lhs.m_p2, rhs.m_p2);
    }

private:
    int32_t * m_p1;
    int32_t * m_p2;
};

class A {
public:
    A();
    A & operator*=(int32_t);
};
A f1();
int32_t f2();
int main ()
{
    f1() *= 10;
//    f2() *= 10;
}

class A0 {
public:
    A0();
    A0 & operator*=(int32_t) &;
};
A f1();
int32_t f2();
int main1 ()
{
    f1() *= 10;
//    f2() *= 10;
}