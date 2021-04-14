typedef struct word Word;

int is_equal(Word* a, Word* b);

void do_things(Word* a, Word* b)
{
    int equal = is_equal(a, b);

    if (equal == 0)
    {
        // ...
    }
}