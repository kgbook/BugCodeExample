class B
{
public:
    B & operator += (B const & other);
};

B const operator + (B const & lhs, B const & rhs)
{
    B result (lhs);
    result += rhs;
    return result;
}

#include <utility>

class A
{
public:
    bool operator < (A const & rhs) const;

    bool operator == (A const & rhs) const
    { return !((*this) < rhs) && !(rhs < (*this)); }

// @@+ Compliant +@@
    bool operator != (A const & rhs) const
    { return std::rel_ops::operator != (*this, rhs); }
    bool operator <= (A const & rhs) const
    { return std::rel_ops::operator <= (*this, rhs); }
    bool operator > (A const & rhs) const
    { return std::rel_ops::operator > (*this, rhs); }
    bool operator >= (A const & rhs) const
    { return std::rel_ops::operator >= (*this, rhs); }
};

#include <cstdint>

class C
{
public:
    C ();

    C& operator ++ ();
    C operator ++ (int)
    {
        C result (*this);
        this->operator ++ ();
        return result;
    }

    C& operator -- ();
    C operator -- (int)
    {
        C result (*this);
        --m_i;
        return result;
    }

public:
    int32_t m_i;
};
