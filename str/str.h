
#include <stdlib.h>
struct str {
  char *data;
  size_t len;
  size_t capacity;
};

struct str *str_new();
void str_init(struct str *);
struct str *str_cat(struct str *, const char *);
void str_free(struct str *);
