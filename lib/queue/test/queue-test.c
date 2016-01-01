/*
 * queue-test.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "../queue.c"

void test_queue_new() {
  queue_t Q = queue_new();
  assert(queue_empty(Q));
  queue_free(Q, NULL);
  printf("queue_new passed\n");
}

void test_enq() {
  queue_t Q = queue_new();
  int x = 1;
  enq(Q, &x);
  assert(!queue_empty(Q));
  queue_free(Q, NULL);
  printf("enq passed\n");
}

void test_deq() {
  queue_t Q = queue_new();
  int x = 1;
  enq(Q, &x);
  int *y = deq(Q);
  assert(*y == 1);
  assert(queue_empty(Q));
  queue_free(Q, NULL);
  printf("deq passed\n");
}

int main(int argc, char **argv) {
  printf("Running queue tests...\n"
         "----------------------\n");

  test_queue_new();
  test_enq();
  test_deq();

  printf("----------------------\n"
         "queue tests passed\n");
  return 0;
}

