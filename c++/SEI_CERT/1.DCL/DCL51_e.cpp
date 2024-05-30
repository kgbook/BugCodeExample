
#ifndef _MY_HEADER_H_
#define _MY_HEADER_H_

// Contents of <my_header.h>

#endif // _MY_HEADER_H_

#include <cstddef>
#include <cinttypes> // for int_fast16_t

unsigned int operator"" x(const char *, std::size_t);

static const std::size_t _max_limit = 1024;
std::size_t _limit = 100;

unsigned int get_value(unsigned int count) {
    return count < _limit ? count : _limit;
}

void f(std::int_fast16_t val) {
    enum { MAX_SIZE = 80 };
    // ...
}
