/*
 * priority_queue-test.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "../priority_queue.c"

bool min(pq_elem x1, pq_elem x2) {
  return *(int*)(x1) < *(int*)(x2);
}

void test_pq_empty() {
  pq_t Q = pq_new(&min);
  assert(pq_empty(Q));
  printf("pq_empty passed\n");
}

void test_array_swap() {
  array_t A = array_new();
  int x1 = 17;
  int x2 = 42;
  array_push(A, &x1);
  array_push(A, &x2);
  assert(array_get(A, 0) == &x1);
  assert(array_get(A, 1) == &x2);
  array_swap(A, 0, 1);
  assert(array_get(A, 0) == &x2);
  assert(array_get(A, 1) == &x1);
  array_swap(A, 1, 0);
  assert(array_get(A, 0) == &x1);
  assert(array_get(A, 1) == &x2);
  array_swap(A, 0, 0);
  assert(array_get(A, 0) == &x1);
  assert(array_get(A, 1) == &x2);
  array_swap(A, 1, 1);
  assert(array_get(A, 0) == &x1);
  assert(array_get(A, 1) == &x2);
  printf("array_swap passed\n");
}

void test_sift_up() {
  pq_t Q = pq_new(&min);
  int x1 = 42;
  array_push(Q->tree, &x1);
  assert(!pq_empty(Q));
  sift_up(Q);
  assert(array_len(Q->tree) == 1);
  assert(array_get(Q->tree, 0) == &x1);
  printf("sift_up passed\n");
}

int main(int argc, char **argv) {
  printf("Running priority_queue tests...\n"
         "----------------------\n");
  test_array_swap();
  test_pq_empty();
  test_sift_up();
  printf("----------------------\n"
         "priority_queue tests passed\n");
  return 0;
}

