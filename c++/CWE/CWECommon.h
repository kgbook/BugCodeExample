//
// Created by joey on 2024/4/22.
//

#ifndef BUGCODEEXAMPLES_CWECOMMON_H
#define BUGCODEEXAMPLES_CWECOMMON_H

#include <cstddef>

struct ExMessage {
    int msgLength;
    char *msgBody;
};

bool GetPasswordFromUser(char* pwd, size_t pwdSize);

bool ConnectToMainframe(char *MFAddr, char* pwd);

void validate_addr_form(char *user_supplied_addr);

int getMessage(int socket, char* buffer, unsigned bufferSize);

ExMessage* recastBuffer(char* buffer);

int processMessage(char* message);

#endif //BUGCODEEXAMPLES_CWECOMMON_H
