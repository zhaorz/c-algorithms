#
# priority_queue-test makefile
#

CC=gcc
CFLAGS=-Wall -std=c99 -pedantic -g
#CFLAGS=-Wall -Wextra -Werror -Wshadow -std=c99 -pedantic -g

default: priority_queue-test

priority_queue-test: priority_queue-test.o array.o xalloc.o
	$(CC) $(CFLAGS) -o priority_queue-test priority_queue-test.o \
	  array.o xalloc.o

priority_queue-test.o: test/priority_queue-test.c
	$(CC) $(CFLAGS) -c test/priority_queue-test.c

priority_queue.o: priority_queue.c priority_queue.h ../array/array.h  \
  ../xalloc/xalloc.h
	$(CC) $(CFLAGS) -c priority_queue.c ../array/array.c \
	  ../xalloc/xalloc.c

array.o: ../array/array.h ../array/array.c
	$(CC) $(CFLAGS) -c ../array/array.c

xalloc.o: ../xalloc/xalloc.c ../xalloc/xalloc.h
	$(CC) $(CFLAGS) -c ../xalloc/xalloc.c

.PHONY: clean
clean:
	rm -Rf priority_queue-test *.o *.dSYM *~
