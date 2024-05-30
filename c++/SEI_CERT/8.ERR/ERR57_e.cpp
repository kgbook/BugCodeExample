
#include <new>

struct SomeType {
    SomeType() noexcept; // Performs nontrivial initialization.
    ~SomeType(); // Performs nontrivial finalization.
    void process_item() noexcept(false);
};

void f() {
    SomeType *pst = new (std::nothrow) SomeType();
    if (!pst) {
        // Handle error
        return;
    }

    try {
        pst->process_item();
    } catch (...) {
        // Process error, but do not recover from it; rethrow.
        throw;
    }
    delete pst;
}

struct A {/* ... */};
struct B {/* ... */};

class C {
    A *a;
    B *b;
protected:
    void init() noexcept(false);
public:
    C() : a(new A()), b(new B()) {
        init();
    }
};
