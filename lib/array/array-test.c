/*
 * array-test.c
 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "array.h"

void test_array_new() {
  array_t A = array_new();
  assert(array_len(A) == 0);
  array_free(A, NULL);
  printf("array_new passed\n");
}

void test_array_push() {
  array_t A = array_new();
  assert(array_len(A) == 0);
  int a = 7;
  int b = 42;
  array_push(A, &a);
  assert(array_len(A) == 1);
  assert(array_get(A, 0) == &a);
  array_push(A, &b);
  assert(array_len(A) == 2);
  assert(array_get(A, 0) == &a);
  assert(array_get(A, 1) == &b);
  array_free(A, NULL);
  printf("array_push passed\n");
}

void test_array_pop() {
  array_t A = array_new();
  int a = 17;
  int b = 42;
  int c = 251;
  int d = 110;
  int e = 122;
  array_push(A, &a);
  assert(array_len(A) == 1);
  assert(array_get(A, 0) == &a);
  int *x = array_pop(A);
  assert(x == &a);
  assert(array_len(A) == 0);
  array_push(A, &a);
  array_push(A, &b);
  assert(array_len(A) == 2);
  assert(array_get(A, 1) == &b);
  array_push(A, &c);
  array_push(A, &d);
  array_push(A, &e);
  assert(array_len(A) == 5);
  assert(array_get(A, 0) == &a);
  assert(array_get(A, 1) == &b);
  assert(array_get(A, 2) == &c);
  assert(array_get(A, 3) == &d);
  assert(array_get(A, 4) == &e);
  int *x4 = array_pop(A);
  int *x3 = array_pop(A);
  int *x2 = array_pop(A);
  int *x1 = array_pop(A);
  int *x0 = array_pop(A);
  assert(array_len(A) == 0);
  assert(x0 == &a);
  assert(x1 == &b);
  assert(x2 == &c);
  assert(x3 == &d);
  assert(x4 == &e);
  array_free(A, NULL);
  printf("array_pop passed\n");
}

int main(int argc, char **argv) {
  printf("Running array tests...\n"
         "----------------------\n");
  test_array_new();
  test_array_push();
  test_array_pop();
  printf("----------------------\n"
         "array tests passed\n");
  return 0;
}
