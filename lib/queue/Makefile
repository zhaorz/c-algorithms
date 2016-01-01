#
# queue-test makefile
#

CC=gcc
CFLAGS=-Wall -std=c99 -pedantic -g
#CFLAGS=-Wall -Wextra -Werror -Wshadow -std=c99 -pedantic -g

default: queue-test

queue-test: queue-test.o xalloc.o
	$(CC) $(CFLAGS) -o queue-test queue-test.o xalloc.o

queue-test.o: test/queue-test.c queue.o
	$(CC) $(CFLAGS) -c test/queue-test.c

queue.o: queue.c queue.h ../xalloc/xalloc.h
	$(CC) $(CFLAGS) -c queue.c ../xalloc/xalloc.c

xalloc.o: ../xalloc/xalloc.c ../xalloc/xalloc.h
	$(CC) $(CFLAGS) -c ../xalloc/xalloc.c

.PHONY: clean
clean:
	rm -Rf queue-test *.o *.dSYM *~
