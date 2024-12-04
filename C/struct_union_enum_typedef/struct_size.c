#include <stdio.h>

typedef struct point {
    int   x;
    int   y;
    char  c[8];
    char *h;
} point;

point p1 = {1};

int main(int argc, char const *argv[]) {
    printf("sizeof p1 = %lu\n", sizeof(p1));
    return 0;
}
