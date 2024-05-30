
#include <iostream>
#include <memory>
#include <cstring>
#include <string>
#include <new>

int main(int argc, const char *argv[]) {
    const char *s = "";
    if (argc > 1) {
        enum { BufferSize = 32 };
        try {
            std::unique_ptr<char[]> buff(new char[BufferSize]);
            std::memset(buff.get(), 0, BufferSize);
            // ...
            s = std::strncpy(buff.get(), argv[1], BufferSize - 1);
        } catch (std::bad_alloc &) {
            // Handle error
        }
    }

    std::cout << s << std::endl;
}

std::string str_func();
void display_string(const char *);

void f() {
    const char *str = str_func().c_str();
    display_string(str);  /* Undefined behavior */
}

void f1() noexcept(false) {
    unsigned char *ptr = static_cast<unsigned char *>(::operator new(0));
    *ptr = 0;
    // ...
    ::operator delete(ptr);
}