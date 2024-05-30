
#include <cstddef>
#include <vector>

void insert_in_table(int *table, std::size_t tableSize, int pos, int value) {
    if (pos >= tableSize) {
        // Handle error
        return;
    }
    table[pos] = value;
}


void insert_in_table(std::vector<int> &table, long long pos, int value) {
    if (pos >= table.size()) {
        // Handle error
        return;
    }
    table[pos] = value;
}

template <typename ForwardIterator>
void f_imp(ForwardIterator b, ForwardIterator e, int val, std::forward_iterator_tag) {
    do {
        *b++ = val;
    } while (b != e);
}

template <typename ForwardIterator>
void f(ForwardIterator b, ForwardIterator e, int val) {
    typename std::iterator_traits<ForwardIterator>::iterator_category cat;
    f_imp(b, e, val, cat);
}