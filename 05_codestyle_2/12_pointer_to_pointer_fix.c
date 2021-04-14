#include <stdlib.h>

typedef struct word {
    char* str;
} Word;

typedef struct line {
    Word* words;
    size_t words_count;
} Line;

Line read_line()
{
    //...
}

int main()
{
    Line line = read_line();
}