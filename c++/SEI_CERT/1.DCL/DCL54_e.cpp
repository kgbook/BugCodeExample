
#include <new>

void *operator new(std::size_t size) noexcept(false) {

throw std::bad_alloc();
}

extern "C++" void update_bookkeeping(void *allocated_ptr, std::size_t size, bool alloc);

struct S {
    void *operator new(std::size_t size) noexcept(false) {
        void *ptr = ::operator new(size);
        update_bookkeeping(ptr, size, true);
        return ptr;
    }
};