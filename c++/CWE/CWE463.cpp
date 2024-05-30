//
// Created by joey on 2024/5/14.
//

#include <cstdio>
#include <malloc.h>

void printString() {
    char *foo;
    int counter;
    foo = (char*)calloc(sizeof(char), 10);

    for (counter=0;counter!=10;counter++) {
        foo[counter]='a';
        printf("%s\n",foo);
    }
}
