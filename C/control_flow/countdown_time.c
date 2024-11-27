#include <stdint.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    // 从输入数开始倒计时
    uint32_t start_number;
    printf("Input countdown number\n");
    scanf("%d", &start_number);

    for (uint32_t i = start_number; i > 0; i--) {
        printf("%d\n", i);
    }

    return 0;
}
