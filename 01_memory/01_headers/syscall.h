#ifndef SYSCALL_H
#define SYSCALL_H

typedef unsigned long int size_t;
typedef long int ssize_t;

void* syscall(
    void* syscall_number,
    void* param1,
    void* param2,
    void* param3,
    void* param4,
    void* param5
);

void write(int fd, void const* data, size_t nbytes);

#endif