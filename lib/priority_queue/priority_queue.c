/*
 * priority_queue.c
 */

#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "../xalloc/xalloc.h"
#include "../array/array.h"
#include "priority_queue.h"

typedef struct pq_header pq;
struct pq_header {
  array_t tree;
  higher_priority_fn *priority;
};

pq *pq_new(higher_priority_fn *priority) {
  pq *Q = xmalloc(sizeof(pq));
  Q->tree = array_new();
  Q->priority = priority;
  return Q;
}

bool pq_empty(pq *Q) {
  return array_len(Q->tree) == 0;
}

void array_swap(array_t A, int i, int j) {
  pq_elem temp = array_get(A, i);
  array_set(A, i, array_get(A, j));
  array_set(A, j, temp);
}

bool is_node(array_t A, int i) {
  return 0 <= i && i < array_len(A);
}

bool tree_left(int i) {
  return i * 2 + 1;
}

bool tree_right(int i) {
  return i * 2 + 2;
}

bool tree_parent(int i) {
  return (i - 1) / 2;
}

void sift_up(pq *Q) {
  int node = array_len(Q->tree);
  int parent = tree_parent(node);
  while (is_node(Q->tree, parent)
      && (*(Q->priority))(array_get(Q->tree, node),
                          array_get(Q->tree, parent)))
  {
    array_swap(Q->tree, parent, node);
    node = parent;
    parent = tree_parent(node);
  }
}

void sift_down(pq *Q) {
  int node = 0;
  int left = tree_left(node);
  int right = tree_right(node);
  int higher_child;
  while (is_node(Q->tree, left) && is_node(Q->tree, right)) {
    if (!is_node(Q->tree, right)) {
      if ((*(Q->priority))(array_get(Q->tree, left),
                         array_get(Q->tree, node))) {
        array_swap(Q->tree, left, node);
        node = left;
        left = tree_left(node);
        right = tree_right(node);
      } else {
        break;
      }
    } else {
      if ((*(Q->priority))(array_get(Q->tree, left),
                         array_get(Q->tree, right)))
        higher_child = left;
      else
        higher_child = right;
      if ((*(Q->priority))(array_get(Q->tree, higher_child),
                         array_get(Q->tree, node))) {
        array_swap(Q->tree, higher_child, node);
        node = higher_child;
        left = tree_left(node);
        right = tree_right(node);
      } else {
        break;
      }
    }
  }
}

void pq_enq(pq *Q, pq_elem x) {
  array_push(Q->tree, x);
  sift_up(Q);
}

pq_elem pq_deq(pq* Q) {
  array_swap(Q->tree, 0, array_len(Q->tree) - 1);
  pq_elem x = array_pop(Q->tree);
  sift_down(Q);
  return x;
}

