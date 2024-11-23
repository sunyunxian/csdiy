#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int32_t  my_int32 = INT32_MAX;
    int64_t  my_int64 = INT64_MAX;
    uint64_t my_uint64 = UINT32_MAX;
    printf("my_int32 = %" PRId32 "\n", my_int32);
    printf("my_int64 = %" PRId64 "\n", my_int64);
    printf("my_uint64 = %" PRIu64 "\n", my_uint64);
    return 0;
}
