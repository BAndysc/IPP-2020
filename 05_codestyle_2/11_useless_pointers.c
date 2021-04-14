#include <stddef.h>

typedef struct word {
    char* string;
} Word;

void print_word(Word** word)
{
    printf("%s\n", (*word)->string);
}