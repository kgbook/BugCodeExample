#include "cstdint"
class C
{
public:
    C () : m_j (0), m_a () {}

    C (C const & other) : m_i (other.m_i), m_j (other.m_j) {}

    explicit C (int32_t j) : m_j (j) {}

private:
    int32_t m_i = 0;
    int32_t m_j;
    int32_t m_a [10];
};