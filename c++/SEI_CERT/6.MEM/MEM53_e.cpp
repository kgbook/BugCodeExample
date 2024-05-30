
#include <memory>
#include <cstdlib>

template <typename T, typename Alloc = std::allocator<T>>
class Container {
    T *underlyingStorage;
    size_t numElements;

    void copy_elements(T *from, T *to, size_t count);

public:
    void reserve(size_t count) {
        if (count > numElements) {
            Alloc alloc;
            T *p = alloc.allocate(count); // Throws on failure
            try {
                copy_elements(underlyingStorage, p, numElements);
            } catch (...) {
                alloc.deallocate(p, count);
                throw;
            }
            underlyingStorage = p;
        }
        numElements = count;
    }

    T &operator[](size_t idx) { return underlyingStorage[idx]; }
    const T &operator[](size_t idx) const { return underlyingStorage[idx]; }
};

struct S {
    S();

    void f();
};

void g() {
    S *s = static_cast<S *>(std::malloc(sizeof(S)));

    s->f();

    std::free(s);
}