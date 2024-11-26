#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int32_t x = 1, y = 2;

    bool greater = x > y;
    printf("x > y = %d\n", greater);

    bool less = x < y;
    printf("x < y = %d\n", less);

    bool equal = x == y;
    printf("x == y = %d\n", equal);

    bool not_equal = x != y;
    printf("x != y = %d\n", not_equal);

    bool greater_or_equal = x >= y;
    printf("x >= y = %d\n", greater_or_equal);

    bool less_or_equal = x <= y;
    printf("x <= y = %d\n", less_or_equal);

    printf("0 & 0 = %d\n", 0 & 0);    // 0
    printf("0 & 1 = %d\n", 0 & 1);    // 0
    printf("1 & 1 = %d\n", 1 & 1);    // 1
    printf("0 | 0 = %d\n", 0 | 0);    // 0
    printf("0 | 1 = %d\n", 0 | 1);    // 1
    printf("1 | 1 = %d\n", 1 | 1);    // 1
    printf("!0 = %d\n", !0);          // 1
    printf("!1 = %d\n", !1);          // 0

    return 0;
}
