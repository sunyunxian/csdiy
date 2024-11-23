#include <stdint.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    // 很多项目里面也可以看到 int8 这种形式，就是 int8_t，而 uint8 或者 u8 这种形式，就是 uint8_t
    int8_t   a = 1;
    int16_t  b = 1;
    int32_t  c = 1;
    int64_t  d = 1;
    uint64_t e = 1;
    printf("%zu\n", sizeof(a));
    printf("%zu\n", sizeof(b));
    printf("%zu\n", sizeof(c));
    printf("%zu\n", sizeof(d));
    printf("%zu\n", sizeof(e));
    return 0;
}
