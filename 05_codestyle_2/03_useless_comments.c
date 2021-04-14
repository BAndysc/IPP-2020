#include <stddef.h>

int main()
{
    // wczytanie znaku
    int character = getchar();

    size_t s; // długość stringa

    // jeśli pierwszy znak to komentarz, to ignoruj linię
    if (is_comment(character))
        ignore_whole_line();
}