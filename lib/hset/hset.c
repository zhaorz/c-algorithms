/* hset.c */

#include <stdlib.h>
#include "hset.h"

struct chain_node {
  elem data;
  struct chain_node* next;
};
typedef struct chain_node chain;

struct hset_header {
  int size;
  int capacity;
  chain **table;
  elem_hash_fn *hash;
  elem_equiv_fn *equiv;
};
typedef struct hset_header *hset;

bool is_hset(hset H)
{
  return H != NULL
    && H->size >= 0
    && H->capacity > 0
    && H->hash != NULL
    && H->equiv != NULL
    && H->table != NULL;
}

int table_index(hset H, elem x)
{
  return (*H->hash)(x) % H->capacity;
}


hset hset_new(int capacity, elem_hash_fn *hash, elem_equiv_fn *equiv)
{
  hset H = malloc(sizeof(struct hset_header));
  H->size = 0;
  H->capacity = capacity;
  H->table = calloc(capacity, sizeof(chain*));
  H->hash = hash;
  H->equiv = equiv;
  return H;
}

void hset_insert(hset H, elem x)
{
  int i;
  chain *p;

  i = table_index(H, x);
  for (p = H->table[i]; p != NULL; p = p->next) {
    /* Check if x is in H already */
    if ((*H->equiv)(p->data, x)) {
      p->data = x;
      return;
    }
  }

  p = malloc(sizeof(chain));
  p->data = x;
  p->next = H->table[i];
  H->table[i] = p;
  (H->size)++;
}

elem hset_lookup(hset H, elem x)
{
  int i;

  i = table_index(H, x);
  for (chain *p = H->table[i]; p != NULL; p = p->next) {
    if ((*H->equiv)(p->data, x)) {
      return p->data;
    }
  }

  return NULL;
}
