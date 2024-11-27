#include <stdint.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    const int32_t TOTAL_LAPS = 10;

    for (int32_t current_lap = 1; current_lap <= 10; current_lap++) {
        printf("current lap = %d\n", current_lap);
    }

    return 0;
}
