
#include <stdexcept>
#include <exception>

class S1 {
    bool has_error() const;

public:
    ~S1() noexcept(false) {
        // Normal processing
        if (has_error()) {
            throw std::logic_error("Something bad");
        }
    }
};

class S2 {
    bool has_error() const;

public:
    ~S2() noexcept(false) {
        // Normal processing
        if (has_error() && !std::uncaught_exception()) {
            throw std::logic_error("Something bad");
        }
    }
};

// Assume that this class is provided by a 3rd party and it is not something
// that can be modified by the user.
class Bad {
public:
    ~Bad() noexcept(false);
};

class SomeClass {
    Bad bad_member;
public:
    ~SomeClass()
    try {
        // ...
    } catch(...) {
        // Handle the exception thrown from the Bad destructor.
    }
};

bool perform_dealloc(void *);

void operator delete(void *ptr) noexcept(false) {
    if (perform_dealloc(ptr)) {
        throw std::logic_error("Something bad");
    }
}