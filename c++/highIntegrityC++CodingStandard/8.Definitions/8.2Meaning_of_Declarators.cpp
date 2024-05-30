#include <cstdint>

void read (int32_t * buffer, int32_t * size);

void read (int32_t * size, int32_t * buffer)
{
}

class B
{
public:
    virtual void foo (int32_t in) = 0;
};

class A : public B
{
public:
    void foo (int32_t) override
    {
    }
};

#include <vector>

void foo (int32_t mode
        , int32_t const * src
        , int32_t src_size
        , int32_t * dest
        , int32_t dest_size
        , bool padding
        , bool compress);

void foo (int32_t flags
        , std::vector <int32_t> const & src
        , std::vector <int32_t> & dest);

class C
{
public:
    C (C const &) = default;

private:
    int32_t m_i;
    int32_t m_j;
};

void foo (C v)
{
}

class D
{
public:
    D (D const &);

private:
    int32_t m_i;
    int32_t m_j;
};

void foo (D v)
{
}


//#include <cstdint>
//#include <memory>
//
//void foo (std::unique_ptr & p_in_out);
//void foo (std::unique_ptr p_sink);
//void foo (std::unique_ptr const & p_impl_detail);