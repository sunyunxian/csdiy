#include <stdint.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    const int8_t TOTAL_LAPS = 10;
    int8_t       current_lap = 0;

    do {
        current_lap++;
        printf("current lap = %d\n", current_lap);
    } while (current_lap < TOTAL_LAPS);

    return 0;
}
