
#include "str.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  int i;
  struct str stack;
  struct str *heap = str_new();
  for (i = 0; i < argc; ++i) {
    if (i != 0)
      str_cat(heap, " ");
    str_cat(heap, argv[i]);
  }
  printf("%s\n", heap->data);

  str_init(&stack);
  for (i = 0; i < argc; ++i) {
    if (i != 0)
      str_cat(&stack, " ");
    str_cat(&stack, argv[i]);
  }
  printf("%s\n", stack.data);
  return 0;
}
