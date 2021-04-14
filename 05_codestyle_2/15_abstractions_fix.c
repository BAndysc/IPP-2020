#include <stdlib.h>
#include <stdio.h>

typedef struct line 
{
    char** words;
    int words_count;
    int words_length;
} Line;

void* realloc_if_needed(void* ptr, size_t element_size, size_t* current_length, size_t required_length)
{
    if (ptr == NULL || required_length >= *current_length)
    {
        *current_length = *current_length * 2 + 1;
        return realloc(ptr, *current_length);
    }
    return ptr;
}

extern void add_word_to_line(Line* line, char* word);

typedef enum readWordResult
{
    READ_WORD_OK,
    READ_WORD_END_OF_FILE,
    READ_WORD_END_OF_LINE
} ReadWordResult;

ReadWordResult read_word(char** word)
{
    char* buffer = NULL;
    size_t word_length = 0;
    size_t word_buffer = 0;

    int character = getchar();
    while (character != EOF && character != '\n' && character != ' ')
    {
        buffer = realloc_if_needed(buffer, sizeof(char), &word_buffer, word_length);
        buffer[word_length++] = character;
        character = getchar();
    }
    *word = buffer;

    if (character == EOF)
        return READ_WORD_END_OF_FILE;
    if (character == '\n')
        return READ_WORD_END_OF_LINE;
    return READ_WORD_OK;
}

Line new_line()
{
    return (Line){.words = NULL, .words_count = 0, .words_length = 0};
}

Line read_line()
{
    Line line = new_line();

    char* word;
    ReadWordResult readResult = read_word(&word);

    while (readResult == READ_WORD_OK)
    {
        add_word_to_line(&line, word);
        readResult = read_word(&word);
    }

    return line;
}