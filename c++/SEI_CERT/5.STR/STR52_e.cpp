
#include <string>

void f(const std::string &input) {
    std::string email;

    // Copy input into email converting ";" to " "
    std::string::iterator loc = email.begin();
    for (auto i = input.begin(), e = input.end(); i != e; ++i, ++loc) {
        email.insert(loc, *i != ';' ? *i : ' ');
    }
}


extern void g(const char *);

void f(std::string &exampleString) {
    const char *data = exampleString.data();
    // ...
    exampleString.replace(0, 2, "bb");
    // ...
    g(data);
}