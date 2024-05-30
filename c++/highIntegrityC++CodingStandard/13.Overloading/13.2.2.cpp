#include <cstdint>

class A
{
public:
    A & operator=(A const &) &;
};

A operator + (A const &, A const &);
const A operator - (A const &, A const &);
A & operator | (A const &, A const &);
bool operator == (A const &, A const &);
int32_t operator < (A const &, A const &);