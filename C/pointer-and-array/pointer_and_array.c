#include <stdio.h>

int main(int argc, char const *argv[]) {
    int  a[3] = {1, 2, 3};
    int  size = sizeof(a) / sizeof(a[0]);
    int *p = a;

    for (int i = 0; i < size; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }

    for (int i = 0; i < size; i++) {
        printf("*(a + %d) = %d\n", i, *(a + i));
    }

    for (int i = 0; i < size; i++) {
        printf("*(p + i) = %d\n", *(p + i));
    }
    // 使用指针倒序
    for (int i = size - 1; i >= 0; i--) {
        printf("*(p + i) = %d\n", *(p + i));
    }
    return 0;
}
