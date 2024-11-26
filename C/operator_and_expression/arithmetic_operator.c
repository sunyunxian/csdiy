#include <stdint.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int32_t x = 10, y = 3;
    printf("x + y = %d\n", x + y);
    printf("x - y = %d\n", x - y);
    printf("x * y = %d\n", x * y);
    printf("x / y = %d\n", x / y);
    printf("x %% y = %d\n", x % y);
    return 0;
}
