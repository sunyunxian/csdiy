#include <stdio.h>

// 如果没有自定义，那么是从 0 开始的，也就是 low = 0，而下面自定义了 low = 1；
typedef enum { low = 1, middle = 2, high = 3 } status;

int main(int argc, char const *argv[]) {
    status x = low;
    // 直接当成 1 进行使用了
    printf("low = %d\n", low);

    if (x == 1) {
        printf("x == low\n");
    }

    return 0;
}
