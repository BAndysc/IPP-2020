#include <stdio.h>
#include <stdlib.h>

int main()
{
    char* buffer;
    size_t bufsize;
  
  
    bufsize = 128;
    buffer = malloc(bufsize);
    getline(&buffer, &bufsize, stdin);

    free(buffer);
}