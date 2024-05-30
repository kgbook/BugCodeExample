//
// Created by joey on 2024/5/14.
//

#include <cstdio>

#define ERROR_VALUE -1

// Example 3
void printString() {
    char *test_string;
    if (ERROR_VALUE)
    {
        test_string = "Hello World!";
    }
    printf("%s", test_string);
}
