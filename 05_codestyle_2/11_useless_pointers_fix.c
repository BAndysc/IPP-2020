#include <stddef.h>

typedef struct word {
    char* string;
} Word;

typedef struct line {
    Word* words;
    size_t words_count;
} Line;

void print_word(Word* word)
{
    printf("%s\n", word->string);
}