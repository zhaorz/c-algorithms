/*
 * array.h
 */

#ifndef _ARRAY_H_
#define _ARRAY_H_

/*********************/
/* Client interface  */
/*********************/

typedef void *array_elem;

typedef void array_elem_free_fn(array_elem x);

/*********************/
/* Library interface */
/*********************/

typedef struct array_header *array_t;

/* @requires: A != NULL
 */
int array_len(array_t A);

/* @ensures: array_new() ==> A such that array_len(A) = 0
 */
array_t array_new();

/* Gets the element at index i
 * @requires: A != NULL
 *            0 <= i < array_len(A)
 */
array_elem array_get(array_t A, int i);

/* Sets A[i] equal to x
 * @requires: A != NULL
 *            0 <= i < array_len(A)
 */
void array_set(array_t A, int i, array_elem x);

/* Adds x to the end of A
 * @requires: A != NULL
 */
void array_push(array_t A, array_elem x);

/* Removes the last element of A
 * @requires: A != NULL
 *            0 < array_len(A)
 */
array_elem array_pop(array_t A);



#endif
