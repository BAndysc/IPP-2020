#include <stdarg.h>
#include <stdbool.h>

#include "syscall.h"
#include "tinylibc.h"
#define stdout 1

static void printString(const char* str)
{
    while (*str != 0)
        write(stdout, str++, 1);
}

void printHex(unsigned int num)
{
    int a = num / 16;
    int b = num % 16;

    char charA = a >= 10 ? ('A' + a - 10) : ('0' + a);
    char charB = b >= 10 ? ('A' + b - 10) : ('0' + b);

    write(stdout, &charA, 1);
    write(stdout, &charB, 1);
}

int printf(const char* fmt, ...)
{
    bool inSpecialCharMode = false;

    va_list args;
    va_start(args, fmt);
 
    while (*fmt != 0) 
    {
        if (*fmt == '%')
            inSpecialCharMode = true;
        else if (inSpecialCharMode)
        {
            if (*fmt == 's')
            {
                const char* str = va_arg(args, const char*);
                printString(str);
            }
            if (*fmt == 'c')
            {
                int c = va_arg(args, int);
                write(stdout, &c, 1);
            }
            else if (*fmt == 'x')
            {
                int i = va_arg(args, int);
                printHex(i);
            }

            inSpecialCharMode = false;
        }
        else
            write(stdout, fmt, 1);

        ++fmt;
    }
 
    va_end(args);

    return 0;
}

int putchar(int c)
{
    write(stdout, &c, 1);
    return 1;
}