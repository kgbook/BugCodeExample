
#include <cstdlib>
#include <string>

void f() {
    std::string tmp(std::getenv("TMP"));
    if (!tmp.empty()) {
        // ...
    }
}