//
// Created by joey on 2024/5/13.
//

#include <cstdlib>
#include <cstdio>

#define EXIST_ERROR true

void foo() {
    char* ptr = (char*)malloc (1024);
    bool abrt = false;
    if (EXIST_ERROR) {
        abrt = true;
        free(ptr);
    }

    if (abrt) {
        printf("operation aborted before commit: %s", ptr);
    }
}
