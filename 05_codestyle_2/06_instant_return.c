#include <ctype.h>
#include <stdbool.h>

bool isDecimal(const char* string)
{
    bool is = true;
    while (*string && is)
    {
        if (!isdigit(*string))
            is = false;
        string++;
    }
    return is;
}