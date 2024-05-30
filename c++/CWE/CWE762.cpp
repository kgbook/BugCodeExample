//
// Created by joey on 2024/5/14.
//

#include <cstdlib>

class BarObj {
    int id;
    int clientNum;
};

void foo(){
    BarObj *ptr = new BarObj();

    /* do some work with ptr here */

    free(ptr);
}
