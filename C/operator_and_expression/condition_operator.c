#include <stdint.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int32_t x = 1, y = 2;
    printf("x > y ? x : y = %d\n", x > y ? x : y);
    return 0;
}
