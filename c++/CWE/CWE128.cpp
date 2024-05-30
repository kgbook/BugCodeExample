//
// Created by joey on 2024/5/8.
//

#include <cstdlib>

struct ImageData {
    int buf[10 * 1024];
    int width;
    int height;
};

void allocateForImage(ImageData*& tablePtr, int num) {
    tablePtr = (ImageData*)malloc(sizeof(ImageData) * num);
}
