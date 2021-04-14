#include <stdbool.h>

bool is_comment(const char* string)
{
    return string[0] == '#';
}