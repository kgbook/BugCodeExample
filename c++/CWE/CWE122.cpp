//
// Created by joey on 2024/4/22.
//

#include <cstdlib>
#include <cstring>

#define BUFFER_SIZE 256
void manipulateString(char* string) {
    char *buf;
    buf = (char *)malloc(sizeof(char)*BUFFER_SIZE);
    strcpy(buf, string);
}
