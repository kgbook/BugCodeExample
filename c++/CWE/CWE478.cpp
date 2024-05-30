//
// Created by joey on 2024/5/14.
//

#include <cstdio>

#define FAILED 0
#define PASSED 1

int security_check(char* data) {
    return -1;
}

void manipulateData(char* data) {
    int result;
    result = security_check(data);
    switch (result) {
        case FAILED:
            printf("Security check failed!\n");
            return;
        case PASSED:
            printf("Security check passed.\n");
            break;
    }

    // manipulate data
    // program execution continues...
}
