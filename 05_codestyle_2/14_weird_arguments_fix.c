#include <stdio.h>
#include <stdbool.h>

void consume_spaces()
{
    int last_char;
    do 
    {
        last_char = getchar();
    } while (isspace(last_char));
    
    ungetc(last_char, stdin);
}

bool is_comment()
{
    int character = getchar();
    if (character == '#')
        return true;
    ungetc(character, stdin);
    return false;
}

char* read_word()
{
    if (is_comment())
        return NULL;

    consume_spaces();

    char* buffer = malloc(10);
    /// while...
}