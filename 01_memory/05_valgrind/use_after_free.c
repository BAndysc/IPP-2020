#include <stdlib.h>

int main()
{
    int* x = malloc(sizeof *x);
    free(x);
    *x = 10;
    return 0;
}