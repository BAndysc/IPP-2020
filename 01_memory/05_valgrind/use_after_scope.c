#include <stdio.h>
#include <stdlib.h>
#include <string.h>

volatile int DEBUG = 1;

int main()
{
    char* ptr = NULL;
    char shortArray[1000];

    shortArray[1000] = 'c';

    if (DEBUG)
    {
        char longArray[1000];
        longArray[500] = 'a';

        ptr = &longArray[500];
    }

    memset(shortArray, 'b', 1000);

    printf("%c\n", *ptr);
}
