#include <stdio.h>

#if 0
int main(int argc, char const *argv[]) {
    int       a = 1;
    long      l = 1L;
    long long ll = 1LL;
    printf("%zu\n", sizeof(a));
    printf("%zu\n", sizeof(l));
    printf("%zu\n", sizeof(ll));
    return 0;
}
#endif

#if 0
#include <stdint.h>

int main(int argc, char const *argv[]) {
    int8_t  a = 1;
    int16_t b = 1;
    int32_t c = 1;
    int64_t d = 1ll;
    // uint8_t;
    // uint16_t;
    // uint32_t;
    // uint64_t;
    printf("%zu\n", sizeof(a));
    printf("%zu\n", sizeof(b));
    printf("%zu\n", sizeof(c));
    printf("%zu\n", sizeof(d));
    return 0;
}
#endif
