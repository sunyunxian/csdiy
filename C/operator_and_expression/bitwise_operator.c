#include <stdint.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    uint32_t x = 3, y = 5;
    // 3 -> 0011
    // 5 -> 0101
    // & -> 0001 -> 1 = 1
    // | -> 0111 -> 4 + 2 + 1 = 7
    // ^ -> 0110 -> 4 + 2 = 6
    printf("x & y = %u\n", x & y);
    printf("x | y = %u\n", x | y);
    printf("x ^ y = %u\n", x ^ y);
    printf("~0B11111111 = %d\n", ~0B11111111);
    printf("%d\n", 2 | 0B11111111);
    return 0;
}
