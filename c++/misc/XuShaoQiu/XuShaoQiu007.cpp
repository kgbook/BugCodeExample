#include <cstdio>
#include <cstring>
#include <cctype>

void showConfigContent() {
    constexpr int LINE_MAX_LEN = 4096;
    const char *filePath = "/home/qiushao/config.ini";
    char line[LINE_MAX_LEN] = {0};
    printf("file path = %s\n", filePath);
    FILE *fp = fopen(filePath, "r");
    if (fp == nullptr) {
        perror("Error opening file");
        return;
    }

    size_t last = 0;
    while (fgets(line + last, 256, fp) != nullptr) {
        int len = (int)strlen(line) - 1; // 去掉字符串结束符 '\0'

        while ((len>=0) && ((line[len]=='\n') || (isspace(line[len])))) {
            // 去除行尾空白字符(空格，TAB, 换行), trim
            line[len]=0 ;
            len-- ;
        }

        if (len < 0) {
            // 空行
            continue;
        }

        if (line[len] == '\\') {
            // 多行配置
            last = len;
            continue;
        }
        printf("%s\n", line);
        last = 0;
        memset(line, 0, LINE_MAX_LEN);
    }

    fclose(fp);
}

int main() {
    showConfigContent();
    char *ptr = nullptr;
    strcpy(ptr, "Hello World!");
    return 0;
}