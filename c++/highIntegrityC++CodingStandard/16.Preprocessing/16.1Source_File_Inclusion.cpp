//#include <xyz>
//#include “xyz”

//#include <stddef>

#define MYHEADER "stddef"
//#include MYHEADER

#define CPU 1044
#ifndef CPU
#error "no CPU defined"
#endif


#ifndef UNIQUE_IDENT_IN_PROJECT
#define UNIQUE_IDENT_IN_PROJECT
// declarations
#endif


#if ! defined (UNIQUE_IDENT_IN_PROJECT)
#define UNIQUE_IDENT_IN_PROJECT
// declarations
#endif

#include <cstdint>
#include <algorithm>

#define MIN(a,b) (((a) < (b)) ? (a) : (b))

void foo (int32_t i, int32_t j)
{
    int32_t k = MIN(i,j);
    k = std::min (i, j);
}

//#include "../../component/include/api.h"
//#include "..\\..\\component\\include\\api.h"
//#include "api.h"

//#include <CStdDef>

#include <cstddef>

#include "cstddef"

#include <cstddef>

//#include <types.h>

//#include "types.h"

#include <cstddef>

#include <vector>

#include <cstddef>

void foo (std::size_t s);

class C;
class D;

C foo (D);

C * bar (D const &);