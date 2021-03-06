#include <stdio.h>
#include <stdbool.h>

typedef struct word 
{
    bool comment;
    bool marked;
} Word;

void do_things(int n, Word** words)
{
    for (int i = 0; i < n - 1; ++i)
    {
        if (words[i] != NULL)
        {
            if (words[i]->comment == false)
            {
                words[i]->marked = true;

                if (similar(words[i+1], words[i]))
                {
                    printf("%d ", i);
                }
            }
        }
    }
}