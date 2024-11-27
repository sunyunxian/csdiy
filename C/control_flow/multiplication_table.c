#include <stdint.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    // 打印 99 乘法表，其实和打印直角三角形是一个概念，都是 2
    // 层循环，外层管行数（高度、宽度），内层管每行的具体数据（长度）
    uint8_t number = 9;
    for (uint8_t outer_i = 1; outer_i <= 9; outer_i++) {
        for (uint8_t inner_i = 1; inner_i <= outer_i; inner_i++) {
            printf("%d * %d = %d\t", inner_i, outer_i, inner_i * outer_i);
        }
        printf("\n");
    }
    return 0;
}
