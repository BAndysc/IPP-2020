#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "string.h"

typedef struct String
{
    char* buffer;
    size_t bufferSize;
    size_t size;
} String;

void stringAppendChar(String* string, char chr)
{
    if (string->size + 1 >= string->bufferSize)
    {
        string->bufferSize = string->bufferSize * 2 + 2;
        string->buffer = realloc(string->buffer, string->bufferSize);
    }
    string->buffer[string->size++] = chr;
    string->buffer[string->size] = 0;
}

void freeString(String* string)
{
    free(string->buffer);
    free(string);
}

String* newString()
{
    String* s = calloc(1, sizeof(String));
    return s;
}

String* newStringFromCString(char* str)
{
    String* s = newString();
    s->buffer = strdup(str);
    s->size = s->bufferSize = strlen(str);
    return s;
}

char* stringRaw(String* string)
{
    return string->buffer;
}

size_t stringLength(String* string)
{
    return string->size;
}

bool stringEquals(String* string, const char* s)
{
    char const *ptr1 = string->buffer;
    char const *ptr2 = s;

    while (*ptr1 && *ptr2) {
        if (*ptr1 != *ptr2)
            return false;
        ptr1++;
        ptr2++;
    }
    return *ptr1 == *ptr2;
}

int charAt(String* string, size_t index)
{
    if (index >= string->size)
        return -1;
    return string->buffer[index];
}