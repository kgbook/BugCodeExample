#include <cstdint>
#include <vector>

void foo (int32_t const * const * const pp);
void foo (int32_t const * const & rp);
void foo (int32_t const (& ra) [10]);
void foo (std::vector <int32_t> const & rv);

// main1 .cpp
int main ();
// main2 .cpp
int main2 (int argc , char * argv []);
// main3 .cpp
int main3 (int argc , char * * argv );