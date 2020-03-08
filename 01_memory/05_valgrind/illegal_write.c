#include <stdlib.h>

int main()
{
    int* x = malloc(sizeof *x);
    x[1] = 4;
    free(x);
    return 0;
}