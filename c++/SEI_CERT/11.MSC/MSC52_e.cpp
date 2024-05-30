//

#include <vector>

std::size_t f(std::vector<int> &v, std::size_t s) try {
    v.resize(s);
    return s;
} catch (...) {

}

int absolute_value(int a) {
    if (a < 0) {
        return -a;
    }
}