#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
    // 进度条
    const uint8_t TOTAL_STEP = 100;
    for (int i = 0; i <= TOTAL_STEP; i++) {
        printf("\r[");
        for (int j = 0; j < i; j++) {
            printf("#");
        }
        for (int j = i; j < TOTAL_STEP; j++) {
            printf(" ");
        }
        printf("]%d%%", (i * 100 / TOTAL_STEP));
        usleep(50000);
        fflush(stdout);
    }
    printf("\n");
    return 0;
}
