//
// Created by joey on 2024/4/26.
//

#include <cstdlib>
#include <cstring>

#define BUFFER_SIZE 256
void manipulateString(char* string) {
    char *buf1 = (char*) malloc(BUFFER_SIZE);
    char *buf2 = (char*) malloc(BUFFER_SIZE);
    strcpy(buf1, string);
    free(buf2);
}
