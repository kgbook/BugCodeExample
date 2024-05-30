//
// Created by joey on 2024/4/26.
//

#include <cstring>
#include <cstdio>

// Example 2
int main(int argc, char **argv)
{
    char Filename[256];
    char Pattern[32];


    strncpy(Filename, argv[1], sizeof(Filename));
    strncpy(Pattern, argv[2], sizeof(Pattern));

    printf("Searching file: %s for the pattern: %s\n", Filename, Pattern);
}
