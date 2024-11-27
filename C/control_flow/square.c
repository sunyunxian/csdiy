#include <stdint.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    // 打印正方形
    uint8_t square = 2;

    for (uint8_t i = 1; i <= square; i++) {
        for (uint8_t j = 1; j <= square; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
