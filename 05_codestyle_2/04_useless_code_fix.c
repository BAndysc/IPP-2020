#include <stdio.h>
#include <stdlib.h>

int main()
{
    char* buffer;
    size_t bufsize;
  
    getline(&buffer, &bufsize, stdin);

    free(buffer);
}