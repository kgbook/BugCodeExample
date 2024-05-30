//
// Created by joey on 2024/5/14.
//

#include <cstdlib>
#include <cstdio>
#include <ctime>

char getRandomChar() {
    std::srand(std::time(nullptr));
    if (rand() % 2) {
        return 'a';
    } else {
        return '\0';
    }
}

void printString() {
    char *foo;
    foo= (char*)malloc(sizeof(char) * 5);
    foo[0]='a';
    foo[1]='a';
    foo[2]= getRandomChar();
    foo[3]='c';
    foo[4]='\0';
    printf("%s\n",foo);
}
