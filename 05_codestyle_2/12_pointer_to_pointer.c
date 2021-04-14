#include <stdlib.h>

typedef struct word {
    char* str;
} Word;

void read_line(Word** words, size_t* words_count)
{
    //...
}

int main()
{
    Word* words;
    size_t words_count;
    read_line(&words, &words_count);
}