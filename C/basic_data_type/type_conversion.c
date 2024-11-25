#include <stdint.h>
#include <stdio.h>

#if 0
int main(int argc, char const *argv[]) {
    int16_t num_16 = 123;
    int32_t num_32;
    num_32 = num_16;
    printf("num_32 = %d\n", num_32);
    return 0;
}
#endif

#if 1
int main(int argc, char const *argv[]) {
    int16_t num_16;
    int32_t num_32 = 99999;
    num_16 = (int16_t)num_32;
    printf("num_16 = %d\nnum_32 = %d\n", num_16, num_32);
    return 0;
}
#endif
