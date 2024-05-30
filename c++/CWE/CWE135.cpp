//
// Created by joey on 2024/5/13.
//

#include <stdio.h>
#include <strings.h>
#include <wchar.h>
#include <cstring>
#include <cstdlib>

int main() {

    wchar_t wideString[] = L"The spazzy orange tiger jumped " \
                            "over the tawny jaguar.";
    wchar_t *newString;

    printf("Wcslen() output: %zu\n", wcslen(wideString));

    newString = (wchar_t *) malloc(wcslen(wideString) * sizeof(wchar_t));
    newString = static_cast<wchar_t *>(memcpy((void *) newString, (void *) wideString,
                                              wcslen(wideString) * sizeof(wchar_t)));

    printf("Wcslen() output: %zu\n", wcslen(newString));
}
