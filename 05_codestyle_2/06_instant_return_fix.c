#include <ctype.h>
#include <stdbool.h>

bool isDecimal(const char* string)
{
    while (*string)
    {
        if (!isdigit(*string))
            return false;
    }
    return true;
}