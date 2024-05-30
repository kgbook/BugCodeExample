//
// Created by joey on 2024/4/22.
//

#include <sys/socket.h>
#include "CWECommon.h"

bool GetPasswordFromUser(char* pwd, size_t pwdSize) {
    if (pwdSize > 0) {
        for (int i = 0; i < pwdSize; i++) {
            pwd[i] = 'a';
        }
        return true;
    }
    return false;
}

bool ConnectToMainframe(char *MFAddr, char* pwd) {
    return true;
}

void validate_addr_form(char *user_supplied_addr) {

}

int getMessage(int socket, char* buffer, unsigned bufferSize) {
    return recv(socket, buffer, bufferSize, 0);
}

ExMessage* recastBuffer(char* buffer) {
    ExMessage* exMessage;
    exMessage->msgLength = buffer[0] * 1000 + buffer[1] * 100 + buffer[2] * 10 + buffer[3];
    exMessage->msgBody = buffer + 4;
    return exMessage;
}

int processMessage(char* message) {
    return 1;
}
