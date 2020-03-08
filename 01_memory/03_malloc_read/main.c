#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "hexdump.h"

void makeDirty(int size)
{
    char* mem = malloc(size);

    for (int i = 0; i < size; ++i)
        mem[i] = rand();

    free(mem);
}

int main(int argc, char** argv)
{
    if (argc < 2)
        return -1;

    srand ((unsigned int) time (NULL));

    long size = atol(argv[1]);

    makeDirty(size);

    void* mem = malloc(size);

    hexdump("malloc", mem, size);

    free(mem);
}