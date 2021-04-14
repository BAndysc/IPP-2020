#include <stdio.h>

typedef struct word {
    int type;
    union {
        char* string;
        long long signed_int;
        unsigned long long unsigned_int;
        float floating_point;
    } value;
} Word;

void print(Word* word)
{
    if (word->type == 0)
        printf("%lld", word->value.signed_int);
    else if (word->type == 1)
        printf("%llu", word->value.unsigned_int);
    else if (word->type == 2)
        printf("%s", word->value.string);
    else if (word->type == 3)
        printf("%f", word->value.floating_point);
}