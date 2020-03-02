flags = -no-pie -nostdlib -fno-asynchronous-unwind-tables

build: syscall tinylibc main.c
	gcc syscall.o syscall_c.o tinylibc.o main.c -o main $(flags)

syscall: syscall.c syscall.h syscall.asm
	nasm syscall.asm -o syscall.o -f elf64
	gcc -c syscall.c -o syscall_c.o $(flags)

tinylibc: tinylibc.c tinylibc.h
	gcc -c tinylibc.c -o tinylibc.o $(flags)

clean:
	rm -rf *.o
	rm -rf main