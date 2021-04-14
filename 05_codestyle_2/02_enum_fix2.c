#include <stdio.h>

typedef enum wordType {
    WORD_TYPE_SIGNED = 0,
    WORD_TYPE_UNSIGNED = 1,
    WORD_TYPE_STRING = 2,
    WORD_TYPE_FLOAT = 3
} WordType;

typedef struct word {
    WordType type;
    union {
        char* string;
        long long signed_int;
        unsigned long long unsigned_int;
        float floating_point;
    } value;
} Word;

void print(Word* word)
{
    if (word->type == WORD_TYPE_SIGNED)
        printf("%lld", word->value.signed_int);
    else if (word->type == WORD_TYPE_UNSIGNED)
        printf("%llu", word->value.unsigned_int);
    else if (word->type == WORD_TYPE_STRING)
        printf("%s", word->value.string);
    else if (word->type == WORD_TYPE_FLOAT)
        printf("%f", word->value.floating_point);
}