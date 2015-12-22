/*
 * queue.c
 */

#include <stdlib.h>
#include <assert.h>
#include "../xalloc/xalloc.h"
#include "queue.h"


/* Lists */

typedef struct list_node list;
struct list_node {
  queue_elem data;
  struct list_node *next;
};

/* TODO: this just diverges, should use a better acylic check */
bool is_list_acyclic(list *start, list *end) {
  list *p = start;
  while (p != end) {
    if (p == NULL) return false;
    p = p->next;
  }
  return true;
}

/* Queues */

typedef struct queue_header queue;
struct queue_header {
  list *front;
  list *back;
};

bool is_queue(queue *Q) {
  return Q != NULL
    && Q->front != NULL
    && Q->back != NULL
    && is_list_acyclic(Q->front, Q->back);
}

bool queue_empty(queue *Q) {
  return Q->front == Q->back;
}

queue *queue_new() {
  queue *Q = xmalloc(sizeof(queue));
  list  *p = xmalloc(sizeof(list));
  Q->front = p;
  Q->back  = p;
  return Q;
}

void enq(queue *Q, queue_elem x) {
  Q->back->data = x;
  Q->back->next = xmalloc(sizeof(list));
  Q->back = Q->back->next;
}

queue_elem deq(queue *Q) {
  assert(!queue_empty(Q));

  queue_elem x = Q->front->data;
  list *p = Q->front;
  Q->front = Q->front->next;
  free(p);
  return x;
}

void queue_free(queue *Q, queue_elem_free_fn *elem_free) {
  while (Q->front != Q->back) {
    list *p = Q->front;
    if (elem_free != NULL)
      elem_free(p->data);
    Q->front = Q->front->next;
    free(p);
  }
  free(Q->front);
  free(Q);
}

