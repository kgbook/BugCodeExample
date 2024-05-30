//
// Created by joey on 2024/4/19.
//

#include <netinet/in.h>
#include <netdb.h>
#include <cstring>
#include "CWECommon.h"

// Example 1
void hostLookup(char *user_supplied_addr){
    struct hostent *hp;
    in_addr_t *addr;
    char hostname[64];
    in_addr_t inet_addr(const char *cp);

    /*routine that ensures user_supplied_addr is in the right format for conversion */
    validate_addr_form(user_supplied_addr);
    addr = reinterpret_cast<in_addr_t *>(inet_addr(user_supplied_addr));
    hp = gethostbyaddr( addr, sizeof(struct in_addr), AF_INET);
    strcpy(hostname, hp->h_name);
}

// Example 4
int getValueFromArray(int *array, int len, int index) {

    int value;

    // check that the array index is less than the maximum
    // length of the array
    if (index < len) {
        // get the value at the specified index of the array
        value = array[index];
    } else {
        value = -1;
    }

    return value;
}
