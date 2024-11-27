#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#if 0
int main(int argc, char const *argv[]) {
    if (1 > 0) {
        printf("1 > 0\n");
    } else if (1 == 0) {
        printf("1 == 0\n");
    } else {
        printf("1< 0\n");
    }

    return 0;
}
#endif

#if 0
int main(int argc, char const *argv[]) {
    bool is_weather_sunny = false;
    bool is_venue_variable = false;

    if (is_weather_sunny && is_venue_variable) {
        printf("Play the game\n");
    } else {
        printf("Not play the game\n");
        if (!is_weather_sunny) {
            printf("weather not sunny\n");
        }
        if (!is_venue_variable) {
            printf("venue not variable\n");
        }
    }
    return 0;
}
#endif

#if 1

int main(int argc, char const *argv[]) {
    int8_t x = 1;
    if (x > 0) {
        printf("1 x > 0\n");
    } else if (x > 0) {
        printf("2 x > 0\n");
    } else {
        printf("x <= 0\n");
    }
    return 0;
}
#endif
