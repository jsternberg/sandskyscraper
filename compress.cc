
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
using namespace std;

string compress(const string& str) {
  if (str.size() <= 2)
    return str;

  string new_str;
  for (string::const_iterator iter = str.begin(), end = str.end();
        iter != end;) {
    char ch = *iter++;
    size_t count = 1;
    for (; iter != end; ++iter) {
      if (*iter != ch)
        break;
      ++count;
    }

    new_str.append(1, ch);
    size_t sz = new_str.size();
    while (count > 0) {
      new_str.append(1, '0'+(count%10));
      count /= 10;
    }
    reverse(new_str.begin()+sz, new_str.end());
  }
  return new_str.size() < str.size() ? new_str : str;
}

int main(int argc, char *argv[]) {
  for (int i = 1; i < argc; ++i) {
    string str = compress(argv[i]);
    printf("%s(%lu) -> %s(%lu)\n",
           argv[i], strlen(argv[i]), str.c_str(), str.size());
  }
  return 0;
}
