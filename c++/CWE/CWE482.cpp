//
// Created by joey on 2024/5/14.
//

#include <cstdio>

void called(int foo) {
    foo == 1;
    if (foo == 1) {
        printf("foo: %d\n", foo);
    }
}

int main() {
    called(2);
    return 0;
}
