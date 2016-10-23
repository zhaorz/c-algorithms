/* palindrome.c */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool is_palindrome(char *s)
{
  int n = strlen(s);

  for (int i = 0; i < (n / 2) + 1; i++) {
    if (s[i] != s[n - i - 1]) return false;
  }

  return true;
}


int main(int argc, char *argv[])
{
  if (argc == 2) {
    char *s = argv[1];

    printf("%d\n", is_palindrome(s));
  }

  return 0;
}
