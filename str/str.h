/// Copyright (c) 2013 Jonathan A. Sternberg
///
/// You should have received a copy of the GNU Lesser General Public License
/// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <stdlib.h>
struct str {
  char *data;
  size_t len;
  size_t capacity;
};

struct str *str_new();
void str_init(struct str *);
struct str *str_cat(struct str *, const char *);
void str_del(struct str *);
void str_free(struct str *);
