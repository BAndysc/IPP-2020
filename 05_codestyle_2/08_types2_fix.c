#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char* buffer;
    size_t bufsize;
  
    getline(&buffer, &bufsize, stdin);

    size_t length = strlen(buffer);
    printf("wczytano %zu znakow\n", length);

    free(buffer);
}