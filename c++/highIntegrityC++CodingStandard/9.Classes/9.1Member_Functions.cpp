#include <cstdint>

class B
{
public:
    explicit B (int32_t i)
            : m_i (i)
            , m_c (0)
    {
    }

    int32_t foo ()
    {
        B tmp (0);
        return tmp.bar ();
    }

    int32_t bar ()
    {
        ++ m_c;
        return m_i;
    }

private:
    int32_t m_i;
    mutable int32_t m_c;
};

class Base
{
public:
    virtual void goodvFn (int32_t a = 0);
    virtual void badvFn (int32_t a = 0);
};

class Derived : public Base
{
public:
    void goodvFn (int32_t a = 0) override;
    void badvFn (int32_t a = 10) override;
};

void foo (Derived& obj)
{
    Base& baseObj = obj;

    baseObj.goodvFn ();
    obj.goodvFn ();

    baseObj.badvFn ();
    obj.badvFn ();
}

class C
{
public:
    C () : m_i (new int32_t) {}

    ~C()
    {
        delete m_i;
    }

    int32_t * get () const
    {
        return m_i;
    }

private:
    int32_t * m_i;

    C (C const &) = delete;
    C & operator = (C const &) & = delete;
};

# include <cstdint>
class D
{
public :
    D ( int32_t * p) : m_i (p) {}
    int32_t * get () const
    {
        return m_i;
    }
private :
    int32_t * m_i;
};

class E
{
public:
    E () : m_i (0) {}

    int32_t & get ()
    {
        return m_i;
    }

    int const & get () const
    {
        return m_i;
    }

private:
    int32_t m_i;
};

class Array
{
public :
    Array () ;
    int32_t & operator [] ( int32_t a)
    {
        return m_x[ a ];
    }
    int32_t operator [] ( int32_t a) const
    {
        return m_x[ a ];
    }
private :
    static const int32_t Max_Size = 10;
    int32_t m_x [ Max_Size ];
};


class Base1
{
public:
    virtual void f1 ();
};

class Derived1 final : public Base
{
public:
    virtual void f2 ();
};
