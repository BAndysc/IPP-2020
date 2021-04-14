#include <stdio.h>
#include <stdlib.h>

typedef struct string 
{
    char* buffer;
    int length;
} String;

String new_word()
{
    String str;
    str.buffer = malloc(8);
    str.length = 0;
    return str;
}

void read_word(String* str)
{
    int size = 8;

    int character = getchar();
    while (character != EOF)
    {
        if (str->length >= size)
        {
            size = size * 2 + 1;
            str->buffer = realloc(str->buffer, size);
        }
        str->buffer[str->length++] = character;
    }
}

int main()
{
    String word = new_word();
    read_word(&word);
}