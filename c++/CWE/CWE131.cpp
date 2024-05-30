//
// Created by joey on 2024/5/8.
//

#include <cstdlib>

void getIds(int*& id) {
    id = (int*) malloc(3);
    if (id == nullptr) {
        return;
    }

    id[0] = 13579;
    id[1] = 24680;
    id[2] = 97531;
}
