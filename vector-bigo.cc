
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <sys/time.h>
using namespace std;

// the contents of the array don't really matter
// not using c++11 so no move semantics, so pass by reference
void fill_array(vector<int>& arr, size_t sz) {
  arr.clear();
  for (size_t i = 0; i < sz; ++i) {
    arr.push_back(0);
  }
}

void reverse(vector<int>& arr) {
  size_t beg = 0, end = arr.size() - 1;
  while (beg < end) {
    swap(arr[beg], arr[end]);
    ++beg; --end;
  }
}

template <typename T>
void time(const char *name, size_t sz) {
  vector<int> arr;
  fill_array(arr, sz);

  T t;
  struct timeval start, end;
  gettimeofday(&start, NULL);
  t(arr);
  gettimeofday(&end, NULL);

  size_t usecs = (end.tv_sec-start.tv_sec)*1000000+(end.tv_usec-start.tv_usec);
  printf("%s: %f msecs\n", name, usecs/1000.0);
}

struct pop_front {
  void operator()(vector<int>& arr) {
    while (!arr.empty())
      // pop_front doesn't exist, which I think proves me right
      // that it's super-inefficient
      arr.erase(arr.begin());
  }
};

struct pop_back {
  void operator()(vector<int>& arr) {
    reverse(arr);
    while (!arr.empty())
      arr.pop_back();
  }
};

int main(int argc, char *argv[]) {
  vector<size_t> args;
  for (int i = 1; i < argc; ++i) {
    char *endptr = NULL;
    size_t n = strtoul(argv[i], &endptr, 10);
    if (*argv[i] == '\0') {
      puts("skipping empty argument");
    } else if (*endptr != '\0') {
      printf("invalid string (not a number): '%s'\n", argv[i]);
    } else {
      args.push_back(n);
    }
  }

  // default if no numbers were given
  if (args.empty())
    args.push_back(10000);

  for (vector<size_t>::const_iterator iter = args.begin(),
         end = args.end(); iter != end; ++iter) {
    time<pop_back>("pop_back", *iter);
    time<pop_front>("pop_front", *iter);
  }
  return 0;
}
