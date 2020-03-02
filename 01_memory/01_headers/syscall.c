#include "syscall.h"

#define SYS_write 1


void write(int fd, void const* data, size_t nbytes)
{
    syscall(
            (void*) SYS_write,
            (void*) (size_t) fd,
            (void*) data,
            (void*) nbytes,
            0, /* ignored */
            0  /* ignored */
        );
}