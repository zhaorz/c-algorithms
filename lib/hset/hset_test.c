/* hset_test.c */

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "hset.c"

bool string_equiv_fn(elem x, elem y)
{
  return strcmp((char*) x, (char*) y) == 0;
}

int string_hash_fn(elem x)
{
  int len = strlen((char*) x);
  int h   = 0;

  for (int i = 0; i < len; i++) {
    int ch = (int)((char*)x)[i];
    h = h * 31;
    h = h + ch;
  }

  return h;
}

void test_hset_new(void)
{
  hset H = hset_new(30, &string_hash_fn, &string_equiv_fn);

  printf("\thset_new\n");

  assert(H != NULL);
  assert(H->size == 0);
  assert(H->capacity == 30);
  assert(H->hash == &string_hash_fn);
  assert(H->equiv == &string_equiv_fn);
  assert(is_hset(H));
}

void test_hset_insert(void)
{
  hset H = hset_new(30, &string_hash_fn, &string_equiv_fn);

  char* a = "hello";
  char* b = "world";
  char* c = "foobar";

  printf("\thset_insert\n");

  assert(is_hset(H));

  hset_insert(H, a);
  assert(is_hset(H));
  assert(H->size == 1);

  hset_insert(H, b);
  assert(is_hset(H));
  assert(H->size == 2);

  hset_insert(H, c);
  assert(is_hset(H));
  assert(H->size == 3);
}

void test_hset_lookup(void)
{
  hset H = hset_new(30, &string_hash_fn, &string_equiv_fn);

  char *a = "hello";
  char *b = "world";
  char *c = "foobar";

  char *ra, *rb, *rc;

  printf("\thset_lookup\n");

  assert(is_hset(H));

  hset_insert(H, a);
  assert(is_hset(H));
  assert(H->size == 1);
  ra = (char*)hset_lookup(H, a);
  assert(ra != NULL);
  assert(string_equiv_fn(a, ra));

  hset_insert(H, b);
  assert(is_hset(H));
  assert(H->size == 2);
  rb = (char*)hset_lookup(H, b);
  assert(rb != NULL);
  assert(string_equiv_fn(b, rb));

  hset_insert(H, c);
  assert(is_hset(H));
  assert(H->size == 3);
  rc = (char*)hset_lookup(H, c);
  assert(rc != NULL);
  assert(string_equiv_fn(c, rc));
}

int main(int argc, char *argv[])
{
  printf("Testing hset...\n");

  test_hset_new();
  test_hset_insert();
  test_hset_lookup();

  printf("Done.\n");
  return 0;
}
