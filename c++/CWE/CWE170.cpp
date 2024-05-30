//
// Created by joey on 2024/5/13.
//

#include <stdio.h>
#include <string.h>

int main() {

    char longString[] = "String signifying nothing";
    char shortString[16];

    strncpy(shortString, longString, 16);
    printf("shortString: %s\n", shortString);
    return (0);
}
