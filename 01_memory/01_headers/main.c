#include "tinylibc.h"

#define LINE_SIZE 32
#define IN_BLOCK 8

char toPrintable(char x)
{
    if (x >= 33 && x <= 126)
        return x;

    return '.';
}

void hexdump(char* title, char* ptr, int size)
{
    printf("%s:\n", title);

    int lines = size / LINE_SIZE + 1;
    for (int line = 0; line < lines; ++line)
    {
        int start = line * LINE_SIZE;
        int end = start + LINE_SIZE;

        for (int i = start; i < end; ++i)
        {
            if (i < size)
                printf("%x ", (unsigned char)ptr[i]);
            else
                printf("   ");

            if ((i + 1) % IN_BLOCK == 0)
                printf("     ");
        }

        for (int i = start; i < end && i < size; ++i)
        {
            char chr = toPrintable(ptr[i]);
            printf("%c", chr);

            if ((i + 1) % IN_BLOCK == 0)
                printf("     ");
        }

        printf("\n");
    }

    printf("\n");
}

char* string1 = "E L I T A R N Y M I M U W";

char mutableString[] = { 'P', 'I', 'E', 'R', 'W', 'S', 'Z', 'A', 'K', 'I', ' ', 'M', 'I', 'M', 'U', 'W', 'I', 'A', 'K', 'I' };

int numbers[] = {
    0x00003721,
    0x00000000,
    0xDEADBEAF,
    0x12345678,
    0x87654321,
    0xAAAAAAAA,
};

char longUninitializedString[0x128];

int main()
{
    char* loremipsum = "Lorem ipsum dolor sit amet";
    char localText[] = { 'T', 'E', 'X', 'T', ' ', 'I', 'N', ' ', 'L', 'O', 'C', 'A', 'L' };
    hexdump(".note.gnu.build-id", (char*)0x0000000000400190, 0x24);
    hexdump(".text", (char*)0x0000000000401000, 0x5bc);
    hexdump(".rodata", (char*)0x0000000000402000, 0x74);
    hexdump(".data", (char*)0x0000000000403080, 0x40);
    hexdump(".bss", (char*)0x4030c0, 0x128);
}
