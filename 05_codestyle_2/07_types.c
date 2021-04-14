#include <stdio.h>

int main()
{
    do 
    {
        int chr = getchar();
        if (chr == EOF)
            break;
        else
            printf("wpisano znak o kodzie: %d\n", chr);
    } while (1);
}