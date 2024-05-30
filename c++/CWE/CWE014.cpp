//
// Created by joey on 2024/4/22.
//

#include <cstring>
#include "CWECommon.h"

void GetData(char *MFAddr) {
    char pwd[64];
    if (GetPasswordFromUser(pwd, sizeof(pwd))) {

        if (ConnectToMainframe(MFAddr, pwd)) {
        // Interaction with mainframe
        }
    }

    memset(pwd, 0, sizeof(pwd));
}
