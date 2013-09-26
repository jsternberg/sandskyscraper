
#include "str.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  int i;
  struct str *s = str_new();
  for (i = 0; i < argc; ++i) {
    if (i != 0)
      str_cat(s, " ");
    str_cat(s, argv[i]);
  }
  printf("%s\n", s->data);
  return 0;
}
