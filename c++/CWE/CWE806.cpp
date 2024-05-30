//
// Created by joey on 2024/5/14.
//

#include <cstring>

void manipulateString() {
    char source[21] = "the character string";
    char dest[12];
    strncpy(dest, source, sizeof(source)-1);
}
