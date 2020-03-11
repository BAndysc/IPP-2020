#include <stdio.h>

#ifdef DEBUG
    #define LOG(x) fprintf(stderr, "%s:%d: %s\n", __FILE__, __LINE__, x)
#else
    #define LOG(x)
#endif

int main()
{
    LOG("test");
}
