#include <unistd.h>

#define STDOUT 1

int main()
{
    write(STDOUT, "mimuw", 5);
}