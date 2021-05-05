#include <stdlib.h>
#include "parser.h"

typedef enum TokenizerState
{
    TOKENIZER_NORMAL,
    TOKENIZER_IN_QUOTATION_MARKS,
    TOKENIZER_SLASH_NORMAL,
    TOKENIZER_SLASH_NORMAL_QUOTATION,
    TOKENIZER_WHITESPACE,
} TokenizerState;

static void appendToken(Tokenized* tokenized, String* str)
{
    if (tokenized->size >= tokenized->bufferSize)
    {
        tokenized->bufferSize = tokenized->bufferSize * 2 + 1;
        tokenized->tokens = realloc(tokenized->tokens, tokenized->bufferSize * sizeof(String*));
    }
    tokenized->tokens[tokenized->size++] = str;
}

void freeTokenized(Tokenized tokenized)
{
    for (size_t i = 0; i < tokenized.size; ++i)
        freeString(tokenized.tokens[i]);
    free(tokenized.tokens);
}

Tokenized Tokenize(String* input)
{
    Tokenized tokenized = {.bufferSize = 0, .size = 0, .tokens = NULL};
    TokenizerState state = TOKENIZER_WHITESPACE;
    String* nextToken = newString();
    char* raw = stringRaw(input);

    for (size_t i = 0; i < stringLength(input); ++i)
    {
        switch (state)
        {
            case TOKENIZER_NORMAL:
                if (raw[i] == '\\')
                    state = TOKENIZER_SLASH_NORMAL;
                else if (raw[i] == ' ')
                {
                    if (stringLength(nextToken) > 0)
                    {
                        appendToken(&tokenized, nextToken);
                        nextToken = newString();
                    }
                    state = TOKENIZER_WHITESPACE;
                }
                else
                    stringAppendChar(nextToken, raw[i]);
                break;

            case TOKENIZER_IN_QUOTATION_MARKS:
                if (raw[i] == '"')
                    state = TOKENIZER_NORMAL;
                else if (raw[i] == '\\')
                    state = TOKENIZER_SLASH_NORMAL_QUOTATION;
                else
                    stringAppendChar(nextToken, raw[i]);
                break;

            case TOKENIZER_SLASH_NORMAL:
                if (raw[i] == 'n')
                    stringAppendChar(nextToken, '\n');
                else
                    stringAppendChar(nextToken, raw[i]);
                state = TOKENIZER_NORMAL;
                break;

            case TOKENIZER_SLASH_NORMAL_QUOTATION:
                if (raw[i] == 'n')
                    stringAppendChar(nextToken, '\n');
                else
                    stringAppendChar(nextToken, raw[i]);
                state = TOKENIZER_IN_QUOTATION_MARKS;
                break;

            case TOKENIZER_WHITESPACE:
                if (raw[i] == '"')
                {
                    state = TOKENIZER_IN_QUOTATION_MARKS;
                } else if (raw[i] != ' ')
                {
                    state = TOKENIZER_NORMAL;
                    i--;
                }
                break;
        }
    }

    if (stringLength(nextToken) > 0)
        appendToken(&tokenized, nextToken);
    else
        freeString(nextToken);

    return tokenized;
}