#include <stdint.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    // 阶乘
    int32_t sum = 0, number;

    printf("Input a number for sum of squares.\n");
    scanf("%d", &number);

    for (uint32_t i = 1; i <= number; i++) {
        sum += i * i;
    }
    printf("sum = %d\n", sum);

    return 0;
}
