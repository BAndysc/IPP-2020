#ifndef IPPSHELLTEST_PARSER_H
#define IPPSHELLTEST_PARSER_H

#include <stddef.h>
#include "string.h"

typedef struct Tokenized
{
    String** tokens;
    size_t size;
    size_t bufferSize;
} Tokenized;

/**
 * Dzieli podany napis po spacjach, wspiera znaki nowej linii oraz cudzysłowy.
 * @param input Napis do przetworzenia.
 * @return Zwraca strukturę z podzielonym napisem.
 */
Tokenized Tokenize(String* input);
void freeTokenized(Tokenized tokenized);

#endif //IPPSHELLTEST_PARSER_H
