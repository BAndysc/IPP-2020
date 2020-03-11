flags = -g -no-pie -nostdlib -fno-asynchronous-unwind-tables

build:
	gcc -c $(flags) externals.c -o externals.o
	gcc -c $(flags) main.c -o main.o
	gcc $(flags) main.o externals.o -o main

symbols: build
	nm -f s main.o

clean:
	rm -rf *.o
	rm -rf main