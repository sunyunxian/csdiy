#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int32_t num = 0;
    printf("输入一个有效数字 0~100, 输入 -1 退出程序\n");

    while (true) {
        scanf("%d", &num);
        if (num == -1) {
            printf("退出程序\n");
            break;
        }
        if (num < 0 || num > 100) {
            printf("无效数字\n");
            continue;
        }
        if (num == 88) {
            goto luck_number;
        }
        if (num % 2 == 0) {
            printf("%d 是偶数\n", num);
        } else {
            printf("%d 是奇数\n", num);
        }
    }
    return 0;
luck_number:
    printf("这是一个 luck number\n");
    return 0;
}
