#include <stdbool.h>

bool is_comment(const char* string)
{
    if ((string[0] == '#') == true)
    {
        return true;
    }
    else
    {
        return false;
    }
}