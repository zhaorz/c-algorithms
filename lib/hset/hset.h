/* hset.h */

#include <stdbool.h>

/************************/
/*** Client interface ***/
/************************/

typedef void* elem;
typedef bool elem_equiv_fn(elem x, elem y);
typedef int elem_hash_fn(elem x);

/*************************/
/*** Library interface ***/
/*************************/

typedef struct hset_header* hset_t;
hset_t hset_new(int capacity, elem_hash_fn* hash, elem_equiv_fn* equiv);
elem hset_lookup(hset_t H, elem x);
void hset_insert(hset_t H, elem x);
