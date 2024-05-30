//
// Created by joey on 2024/5/14.
//

int getCurrentDirectory(int size, char* currentDirectory);
bool PathAppend(char* outputDirectoryName, char* suffix);
bool SHCreateDirectoryEx(char*, char* outputDirectoryName, char*);
char* StrDup(char*);

char *createOutputDirectory(char *name) {
    char outputDirectoryName[128];
    if (getCurrentDirectory(128, outputDirectoryName) == 0) {
        return nullptr;
    }
    if (!PathAppend(outputDirectoryName, "output")) {
        return nullptr;
    }
    if (!PathAppend(outputDirectoryName, name)) {
        return nullptr;
    }
    if (SHCreateDirectoryEx(nullptr, outputDirectoryName, nullptr) != 0) {
        return nullptr;
    }
    return StrDup(outputDirectoryName);
}
