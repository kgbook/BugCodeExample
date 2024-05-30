#include <cstdint>

class C
{
public:
    C (const C&);
    C ();
    C (int32_t, int32_t);

    explicit C (int32_t);
    C (double);
    C (float f, int32_t i = 0);
    C (int32_t i = 0, float f = 0.0);
    operator int32_t () const;
    explicit operator double () const;
};
