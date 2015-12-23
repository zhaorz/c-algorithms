/*
 * array.c
 */

#include <stdlib.h>
#include <limits.h>
#include <assert.h>
#include "../xalloc/xalloc.h"
#include "array.h"

typedef struct array_header array;
struct array_header {
  int size;           /* 0 <= size && size < limit */
  int limit;          /* 0 < limit */
  array_elem *data;  /* len(data) == limit */
};

int array_len(array *A) {
  return A->size;
}

array *array_new() {
  array *A = xmalloc(sizeof(array));
  A->size = 0;
  A->limit = 2;
  A->data = xcalloc(sizeof(array_elem), A->limit);
  return A;
}

array_elem array_get(array *A, int i) {
  return A->data[i];
}

void array_set(array *A, int i, array_elem x) {
  A->data[i] = x;
}

void array_resize(array *A) {
  if (A->size == A->limit) {
    assert(A->limit < INT_MAX / 2);
    A->limit = A->limit * 2;
  } else if (A->size < A->limit / 4) {
    A->limit = A->limit / 2;
  } else {
    return;
  }

  array_elem *B = xcalloc(sizeof(array_elem), A->limit);
  for (int i = 0; i < A->size; i++)
    B[i] = A->data[i];

  A->data = B;
}

void array_push(array *A, array_elem x) {
  A->data[A->size] = x;
  A->size++;
  array_resize(A);
}

array_elem array_pop(array *A) {
  (A->size)--;
  array_elem x = A->data[A->size];
  array_resize(A);
  return x;
}

