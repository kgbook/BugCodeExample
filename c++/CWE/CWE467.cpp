//
// Created by joey on 2024/5/14.
//

#include <cstdlib>
#include <cstdio>

void printDouble() {
    double *foo;
    foo = (double*)malloc(sizeof(foo));
    *foo = 10;
    printf("foo: %f", *foo);
}
