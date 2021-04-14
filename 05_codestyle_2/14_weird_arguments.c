#include <stdio.h>

void consume_spaces(int* last_char)
{
    if (*last_char == -1)
        *last_char = getchar();

    while (isspace(*last_char))
        *last_char = getchar();
}

char* read_word()
{
    int character = getchar();
    if (character == '#')
        return NULL;

    consume_spaces(character);

    char* buffer = malloc(10);
    buffer[0] = character;
    /// while...
}