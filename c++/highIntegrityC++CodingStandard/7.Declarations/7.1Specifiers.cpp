#include <cstdint>

extern int32_t const * p, v;

typedef int32_t* Pointer, Value;

//# include <vector>
//# include <cstdint>
//void foo (std :: vector  const & v) {
//    for (auto iter(v.begin()), end(v.end())
//            ; iter != end; ++iter) {
//// ...
//    }
//}

struct S
{
    char* p1;
    const char* p2;
    char* const p3;
    const char* const p4;
};

void foo (const char * const p);

void bar (S & s)
{
    foo (s.p1);
    foo (s.p2);
    foo (s.p3);
    foo (s.p4);
}

struct A { };

const int f1 ();
const A f2 () ;
A f3 ();

typedef int int32_t;
int typedef int32_e;

class C
{
public:
    virtual inline void f1 ();
    inline virtual void f2 ();
    void inline virtual f3 ();

private:
    int32_t mutable _i;
};

typedef int32_t * PINT;

void foo (const PINT p1
        , PINT const p2);

void bar (int32_t const & in);