#include <stdio.h>

#define MAX(x, y)     ((x > y) ? (x) : (y))
#define PRINT_INT(x)  printf("%d\n", x)
#define PRINT_INT_(x) printf(#x " = %d\n", x)

int main(int argc, char const *argv[]) {
    printf("%d or %d max: %d\n", 1, 2, MAX(1, 2));
    PRINT_INT(1 + 1);
    PRINT_INT_(1 + 1);

    return 0;
}
