/*
 * priority_queue.h
 */

#include <stdbool.h>

#ifndef _PRIORITY_QUEUE_H_
#define _PRIORITY_QUEUE_H_

/*********************/
/* Client interface */
/*********************/

typedef void *pq_elem;

/**
 * true iff e1 has higher priority than e2
 */
typedef bool higher_priority_fn(pq_elem e1, pq_elem e2);

typedef void pq_elem_free_fn(pq_elem x);

/*********************/
/* Library interface */
/*********************/

// typedef ______* queue_t;
typedef struct pq_header *pq_t;

/**
 * @requires Q != NULL
 */
bool pq_empty(pq_t Q);

pq_t pq_new(higher_priority_fn *priority);

/**
 * Enqueues x in Q.
 */
void pq_enq(pq_t Q, pq_elem x);

/**
 * Dequeues the highest priority element.
 * @requires: !pq_empty(Q)
 */
pq_elem pq_deq(pq_t Q);

/**
 * Returns the highest priority element without dequeuing.
 * @requires: !pq_empty(Q)
 */
pq_elem pq_peek(pq_t Q);

void pq_free(pq_t Q, pq_elem_free_fn *elem_free);

#endif

