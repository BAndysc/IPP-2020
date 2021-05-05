#include <stdio.h>
#include "input.h"

String* readLine()
{
    String* string = newString();
    int chr = getchar();

    while (chr != EOF && chr != '\n')
    {
        stringAppendChar(string, chr);
        chr = getchar();
    }

    if (chr == EOF && stringLength(string) == 0)
    {
        freeString(string);
        return NULL;
    }

    return string;
}