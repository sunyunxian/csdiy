#include <stdint.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int32_t x, y, z;
    x = y = z = 1;
    printf("x = %d y = %d z = %d\n", x, y, z);

    printf("x += 1 = %d\n", x += 1);

    return 0;
}
