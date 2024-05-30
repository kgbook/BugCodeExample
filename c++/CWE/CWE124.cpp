//
// Created by joey on 2024/4/26.
//

#include <cstdlib>
#include <cctype>

char* trimTrailingWhitespace(char *strMessage, int length) {
    char *retMessage;

    // copy input string to a temporary string
    char message[length+1];
    int index;
    for (index = 0; index < length; index++) {
        message[index] = strMessage[index];
    }
    message[index] = '\0';

    // trim trailing whitespace
    int len = index-1;
    while (std::isspace(message[len])) {
        message[len] = '\0';
        len--;
    }

    // return string without trailing whitespace
    retMessage = message;
    return retMessage;
}
