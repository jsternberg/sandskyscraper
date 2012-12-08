
#include <stdio.h>

/// Iterative version of gcd.
template <typename T>
T gcd(T a, T b) {
    while (b) {
        T val = a;
        a = b;
        b = val % b;
    }
    return a;
}

/// Recursive version of gcd.
template <typename T>
T gcdr(T a, T b) {
    return b == 0 ? a : gcd(b, a % b);
}

#define CHECK_EQUAL(code, expected) \
    { int res = code; printf("  %s = %d %s\n", #code, res, res == expected ? "ok" : "not_ok"); }

void test_gcd_algorithm(int (*gcd)(int, int)) {
    CHECK_EQUAL(gcd(48, 18), 6);
    CHECK_EQUAL(gcd(51, 12), 3);
    CHECK_EQUAL(gcd(118, 17), 1);
}

int main() {
    puts("iterative");
    test_gcd_algorithm(&gcd<int>);

    puts("recursive");
    test_gcd_algorithm(&gcdr<int>);
    return 0;
}
