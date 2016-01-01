#
# array-test makefile
#

CC=gcc
CFLAGS=-Wall -std=c99 -pedantic -g
#CFLAGS=-Wall -Wextra -Werror -Wshadow -std=c99 -pedantic -g

default: array-test

array-test: array-test.o xalloc.o
	$(CC) $(CFLAGS) -o array-test array-test.o xalloc.o

array-test.o: test/array-test.c array.o
	$(CC) $(CFLAGS) -c test/array-test.c

array.o: array.c array.h ../xalloc/xalloc.h
	$(CC) $(CFLAGS) -c array.c ../xalloc/xalloc.c

xalloc.o: ../xalloc/xalloc.c ../xalloc/xalloc.h
	$(CC) $(CFLAGS) -c ../xalloc/xalloc.c

.PHONY: clean
clean:
	rm -Rf array-test *.o *.dSYM *~
