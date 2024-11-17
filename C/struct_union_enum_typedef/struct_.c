#include <stdio.h>

// struct point {
//     int x;
//     int y;
// };

struct point {
    int   x;
    int   y;
    char  c[8];
    char *h;
} p1 = {1};

int main(int argc, char const *argv[]) {
    // struct point p1 = {1, 2};
    // struct point p1 = {.x = 1, .y = 2};
    // printf("p1.x = %d\t p1.y = %d\n", p1.x, p1.y);
    printf("sizeof p1 = %lu\n", sizeof(p1));
    return 0;
}
