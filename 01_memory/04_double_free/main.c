#include <stdlib.h>

int main()
{
    int* x = malloc(sizeof *x);
    free(x);
    free(x);
    return 0;
}