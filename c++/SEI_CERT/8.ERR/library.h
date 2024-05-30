// ERR59-CPP. Do not throw an exception across execution boundaries

// library.h
void func() noexcept(false); // Implemented by the library

// library.cpp
void func() noexcept(false) {
    int i = 11;
    // ...
    if (1!=(12-i)) {
        throw 42;
    }
}
