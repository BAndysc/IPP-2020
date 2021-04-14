#include <stdlib.h>
#include <stdio.h>

typedef struct line
{
    char** words;
    int words_count;
} Line;

Line read_line()
{
    Line line;
    line.words = NULL;
    line.words_count = 0;
    int line_length = 0;
    char* word = NULL;
    int word_length = 0;
    int word_buffer = 0;

    int character = getchar();
    while (character != EOF && character != '\n')
    {
        if (character == ' ')
        {
            // dodanie słowa do tablicy
            if (line.words == NULL || line.words_count >= line_length)
            {
                line_length = line_length * 2 + 1;
                line.words = realloc(line.words, line_length);
            }
            line.words[line.words_count++] = word;
            word = NULL;
        }
        else
        {
            // wczytanie słowa
            if (word == NULL || word_length >= word_buffer)
            {
                word_buffer = word_buffer * 2 + 1;
                word = realloc(word, word_buffer);
            }
            word[word_length++] = character;
        }

        character = getchar();
    }
}