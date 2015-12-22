#
# queue makefile
#

CC=gcc
CFLAGS=-Wall -std=c99 -pedantic -g
#CFLAGS=-Wall -Wextra -Werror -Wshadow -std=c99 -pedantic -g

default: queue

queue: queue-test.o queue.o xalloc.o
	$(CC) $(CFLAGS) -o queue queue-test.o queue.o xalloc.o

queue-test.o: queue-test.c queue.h
	$(CC) $(CFLAGS) -c queue-test.c

queue.o: queue.c queue.h ../xalloc/xalloc.h
	$(CC) $(CFLAGS) -c queue.c ../xalloc/xalloc.c

xalloc.o: ../xalloc/xalloc.c ../xalloc/xalloc.h
	$(CC) $(CFLAGS) -c ../xalloc/xalloc.c

.PHONY: clean
clean:
	rm -Rf queue *.o *.dSYM
