#include <stdint.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int32_t x = 1, y = 2, z = 3;
    int32_t rst = (x += 1, y += 1, z += 1);
    printf("x = %d y = %d z = %d rst = %d\n", x, y, z, rst);

    return 0;
}
