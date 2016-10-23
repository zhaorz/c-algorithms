#
# hset-test makefile
#

CC=gcc
CFLAGS=-Wall -std=c99 -pedantic -g
#CFLAGS=-Wall -Wextra -Werror -Wshadow -std=c99 -pedantic -g

default: hset_test

hset_test: hset.c hset_test.c
		$(CC) $(CFLAGS) -o hset_test hset_test.c

.PHONY: clean
clean:
		rm -Rf hset_test *.o *.dSYM *~
