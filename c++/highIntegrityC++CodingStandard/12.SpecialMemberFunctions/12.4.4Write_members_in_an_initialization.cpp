#include <cstdint>

class B {};

class VB : public virtual B {};

class C {};

class DC : public VB, public C
{
public:
    DC()
            : B(), VB(), C(), i (1), c()
    {}

private:
    int32_t i;
    C c;
};

class A1 {
public:
    A1()
    {
        init(10, 20);
    }

    A1(int i)
    {
        init(i, 20);
    }
private:
    void init(int32_t i, int32_t j);

private:
    int32_t m_i;
    int32_t m_j;
};

class A2 {
public:
    A2()
            : A2(10, 20)
    {
    }

    A2(int32_t i)
            : A2(i, 20)
    {
    }

private:
    A2(int32_t i, int32_t j)
            : m_i(i)
            , m_j(j)
    {
    }

private:
    int32_t m_i;
    int32_t m_j;
};