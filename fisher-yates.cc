
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <algorithm>
#include <vector>
using namespace std;

template <typename Array>
void shuffle(Array& arr) {
    // Because of the use of rand, this obviously isn't a true
    // random shuffle. You can easily just replace this with something
    // like the mersenne twister.
    for (size_t sz = arr.size(); sz > 0; --sz) {
        swap(arr[rand() % sz], arr[sz-1]);
    }
}

int main() {
    srand(time(NULL));

    vector<int> arr(52);
    for (int i = 0; i < 52; ++i) {
        arr[i] = i;
    }
    shuffle(arr);

    for (vector<int>::const_iterator iter = arr.begin(),
             end = arr.end(); iter != end; ++iter) {
        printf("%d\n", *iter);
    }
    return 0;
}
