
#include <string>

extern std::size_t get_index();

void f() {
    std::string s("01234567");
    s[get_index()] = '1';
}

#include <locale>

void capitalize(std::string &s) {
    std::locale loc;
    s.front() = std::use_facet<std::ctype<char>>(loc).toupper(s.front());
}