VALGRIND_FLAGS = --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=all
VALGRIND = valgrind $(VALGRIND_FLAGS)

%.o: %.c
	gcc -g $< -o $@

double_free: double_free.o
	$(VALGRIND) ./double_free.o

double_free_asan:
	clang -g double_free.c -o double_free_asan.o -fsanitize=address
	./double_free_asan.o

ok: ok.o
	$(VALGRIND) ./ok.o

use_after_free: use_after_free.o
	$(VALGRIND) ./use_after_free.o

use_after_free_asan:
	clang -g use_after_free.c -o use_after_free_asan.o -fsanitize=address
	./use_after_free_asan.o

illegal_write: illegal_write.o
	$(VALGRIND) ./illegal_write.o

illegal_write_asan:
	clang -g illegal_write.c -o illegal_write_asan.o -fsanitize=address
	./illegal_write_asan.o

uninitialized_read: uninitialized_read.o
	$(VALGRIND) ./uninitialized_read.o

uninitialized_read_asan:
	clang -g uninitialized_read.c -o uninitialized_read_asan.o -fsanitize=address
	./uninitialized_read_asan.o

leak: leak.o
	$(VALGRIND) ./leak.o

leak_asan:
	clang -g leak.c -o leak_asan.o -fsanitize=address
	./leak_asan.o

illegal_read: illegal_read.o
	$(VALGRIND) ./illegal_read.o

illegal_read_asan:
	clang -g illegal_read.c -o illegal_read_asan.o -fsanitize=address
	./illegal_read_asan.o

use_after_scope: use_after_scope.o
	$(VALGRIND) ./use_after_scope.o

use_after_scope_asan:
	clang -g use_after_scope.c -o use_after_scope_asan.o -fsanitize=address
	./use_after_scope_asan.o

clean:
	rm -rf *.o