#include <stdio.h>

#define LINE_SIZE 32
#define IN_BLOCK 8

#include "hexdump.h"

char toPrintable(char x)
{
    if (x >= 33 && x <= 126)
        return x;

    return '.';
}

void hexdump(char* title, char* ptr, int size)
{
    printf("%s:\n", title);

    int lines = size / LINE_SIZE + 1;
    for (int line = 0; line < lines; ++line)
    {
        int start = line * LINE_SIZE;
        int end = start + LINE_SIZE;

        for (int i = start; i < end; ++i)
        {
            if (i < size)
                printf("%02x ", (unsigned char)ptr[i]);
            else
                printf("   ");

            if ((i + 1) % IN_BLOCK == 0)
                printf("     ");
        }

        for (int i = start; i < end && i < size; ++i)
        {
            char chr = toPrintable(ptr[i]);
            printf("%c", chr);

            if ((i + 1) % IN_BLOCK == 0)
                printf("     ");
        }

        printf("\n");
    }

    printf("\n");
}