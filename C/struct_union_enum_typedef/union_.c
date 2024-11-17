#include <stdio.h>

union point {
    int x;
    int y;
};

int main(int argc, char const *argv[]) {
    union point p1 = {1, 2};
    printf("union p1 x = %d, y = %d\n", p1.x, p1.y);
    return 0;
}
