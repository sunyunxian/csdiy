#include <stdint.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    char c = 'a';
    char h = '1';
    printf("c = %c c = %d\n", c, c);
    printf("h = %c c = %d\n", h, h);

    for (int8_t i = -1; i < INT8_MAX; i++) {
        printf("i = %d char i = %c\n", i + 1, i + 1);
    }
    return 0;
}
