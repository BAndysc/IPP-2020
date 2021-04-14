#include <stdbool.h>

typedef struct word Word;

bool is_equal(Word* a, Word* b);

void do_things(Word* a, Word* b)
{
    if (is_equal(a, b) == false)
    {
        // ...
    }
}