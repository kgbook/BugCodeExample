#include <cstdio>
#include <string>
#include <cstring>

std::string getConfigPath() {
    return std::string{"/home/qiushao/config.ini"};
}

void showConfigContent() {
    const char *filePath = getConfigPath().c_str();
    char buffer[256] = {0};
    printf("file path = %s\n", filePath);
    FILE *fp = fopen(filePath, "r");
    if (fp == nullptr) {
        perror("Error opening file");
        return;
    }
    while (fgets(buffer, 256, fp) != nullptr) {
        printf("%s\n", buffer);
        memset(buffer, 0, 256);
    }

    fclose(fp);
}

int main() {
    showConfigContent();
    return 0;
}