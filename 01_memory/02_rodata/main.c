#include <stdio.h>
#include <stdlib.h>

int main()
{
    char* text = "aaaaaaaaa";
    text[2] = 'b';
    printf("%s\n", text);
}

