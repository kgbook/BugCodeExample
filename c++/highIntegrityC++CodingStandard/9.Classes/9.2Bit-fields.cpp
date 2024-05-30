#include <cstdint>
enum E : uint8_t { ONE, TWO, THREE };
struct S
{
    int32_t a : 2;
    uint8_t b : 2;
    bool    c : 1;
    char    d : 2;
    wchar_t e : 2;
    E       f : 2;
};
