#include <stdint.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    // 初始化数组
    uint32_t a[3] = {1, 2, 3};

    // 根据索引获取值
    printf("a[2] = %d\n", a[2]);

    // 获取长度
    uint32_t length = sizeof(a) / sizeof(a[0]);

    // 遍历数组
    for (u_int32_t i = 0; i < length; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }
    // copy 数组
    uint32_t b[3];
    memcpy(b, a, sizeof(a));
    for (u_int32_t i = 0; i < length; i++) {
        printf("b[%d] = %d\n", i, b[i]);
    }

    return 0;
}
