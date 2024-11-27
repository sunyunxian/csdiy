#include <stdint.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    const int8_t TOTAL_LAPS = 10;
    int8_t       current_lap = 0;

    while (current_lap < TOTAL_LAPS) {
        current_lap++;
        printf("current_lap = %d\n", current_lap);
    }

    return 0;
}
