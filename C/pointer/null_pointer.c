#include <stdio.h>

int main(int argc, char const *argv[]) {
    int *p = NULL;
    // 打印一下地址
    printf("p = %p\n", p);    // 0x0
    printf("p = %d\n", p);    // 0

    if (p == NULL) {
        printf("p is NULL pointer\n");
    }

    return 0;
}
