//
// Created by joey on 2024/5/13.
//

#include <cstdlib>
#include <cstdio>

#define BLOCK_SIZE 1024

int read(int fd, char *buf, int i) {
    FILE* file = fopen("test/" + fd, "rb");
    return fread(buf, sizeof(char), i, file);
}

char* getBlock(int fd) {
    char* buf = (char*) malloc(BLOCK_SIZE);
    if (!buf) {
        return nullptr;
    }
    if (read(fd, buf, BLOCK_SIZE) != BLOCK_SIZE) {
        return nullptr;
    }
    return buf;
}
