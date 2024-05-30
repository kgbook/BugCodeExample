
struct S {
    S() noexcept(false);
};

static S globalS;

extern int f() noexcept(false);
int i = f();

#include <string>

static const std::string global("...");

int main()
try {
    // ...
} catch(...) {
    // IMPORTANT: Will not catch exceptions thrown
    // from the constructor of global
}