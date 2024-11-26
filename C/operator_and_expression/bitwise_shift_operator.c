#include <math.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    // 5 -> 0000 0101
    // left shift 0000 1010 -> 8 + 0 + 2 + 0 = 10
    // right shift 0000 0010 -> 2 + 0 = 2
    printf("5 << 1 = %d\n", 5 << 1);
    printf("5 >> 1 = %d\n", 5 >> 1);

    printf("5 << 2 = %d 5 * 2^2 = %.0f\n", 5 << 2, 5 * pow(2, 2));
    printf("5 << 3 = %d 5 * 2^3 = %.0f\n", 5 << 3, 5 * pow(2, 3));
    return 0;
}
