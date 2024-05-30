//
// Created by joey on 2024/5/13.
//

#include <cstdlib>

#define EXIST_ERROR true

void manipulateString() {
    char* ptr = (char*)malloc (1024);

    if (EXIST_ERROR) {
        free(ptr);
    }

    free(ptr);
}
