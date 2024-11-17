#include <stdio.h>

typedef const char *String;

typedef struct point {
    int x;
    int y;
} point;

int main(int argc, char const *argv[]) {
    String s = "string";
    printf("s = %s\n", s);

    point p = {1, 2};
    printf("p x = %d, y = %d\n", p.x, p.y);
    return 0;
}
