#include <stdint.h>
#include <stdio.h>

#if 1
int main(int argc, char const *argv[]) {
    const int8_t status = 2;

    switch (status) {
        case 1:
            printf("status = 1\n");
            break;
        case 0:
            printf("status = 0\n");
            break;
        default:
            printf("Unknown status\n");
            break;
    }

    return 0;
}
#endif
