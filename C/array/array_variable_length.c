#include <stdint.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    // c99 支持变长数组，也就是初始化数组的时候不使用常量表达式也可以

    u_int32_t length;
    scanf("%d", &length);
    u_int32_t a[length];

    return 0;
}
