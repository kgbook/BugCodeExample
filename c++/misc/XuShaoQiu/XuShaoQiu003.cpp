#include <cstdio>
#include <thread>
#include <cstring>

static std::thread thread;

void theadLoop(void *arg) {
    char *filePath = static_cast<char *>(arg);
    char tmpPath[256] = {0};
    char buffer[256] = {0};
    memset(tmpPath, 0, 256);
    memset(buffer, 0, 256);
    strcpy(tmpPath, filePath);
    printf("file path = %s\n", tmpPath);
    FILE *fp = fopen(tmpPath, "rb");
    if (fp == nullptr) {
        return;
    }
    while (fgets(buffer, 256, fp) != nullptr) {
        printf("%s\n", buffer);
        memset(buffer, 0, 256);
    }

    fclose(fp);
}

void createThread() {
    char filePath[256] = {0};
    sprintf(filePath, "/home/qiushao/config.ini");
    thread = std::thread(theadLoop, filePath);
}

int main() {
    createThread();
    thread.join();
    return 0;
}