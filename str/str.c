/// Copyright (c) 2013 Jonathan A. Sternberg
///
/// You should have received a copy of the GNU Lesser General Public License
/// along with this program.  If not, see <http://www.gnu.org/licenses/>.
//
#include "str.h"
#include <stdlib.h>
#include <string.h>

struct str *str_new() {
  struct str *self = malloc(sizeof(struct str));
  if (!self) {
    return NULL;
  }
  str_init(self);
  return self;
}

void str_init(struct str *self) {
  self->data = NULL;
  self->len = 0;
  self->capacity = 0;
}

struct str *str_cat(struct str *self, const char *other) {
  size_t sz = strlen(other);
  while (self->len+sz+1 > self->capacity) {
    size_t new_capacity = self->capacity ? self->capacity << 1 : 32;
    char *data = realloc(self->data, new_capacity);
    if (!data)
      return NULL;
    self->data = data;
    self->capacity = new_capacity;
  }
  memcpy(self->data+self->len, other, sz);
  self->len += sz;
  self->data[self->len] = '\0';
  return self;
}

void str_del(struct str *self) {
  if (self) free(self->data);
  self->data = NULL;
  self->len = 0;
  self->capacity = 0;
}

void str_free(struct str *self) {
  if (self) free(self->data);
  free(self);
}
