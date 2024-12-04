#include <stdint.h>
#include <stdio.h>

typedef union point {
    uint32_t x;
    uint8_t  y;
} point;

int main(int argc, char const *argv[]) {
    // 用了 x 的值，所以就都是 1
    point p1 = {.x = 1};
    printf("union p1 x = %d, y = %d\n", p1.x, p1.y);

    // 用了 y 的值，所以所有的值都是 100
    point p2 = {.y = 100};
    printf("union p2 x = %d, y = %d\n", p2.x, p2.y);
    return 0;
}
