#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    // int  a[3] = {1, 2, 3};
    int *p;
    p = malloc(3 * 4);
    *p = 1;
    *(p + 1) = 2;
    *(p + 2) = 3;

    printf("p[0] = %d\n", p[0]);
    printf("p[1] = %d\n", p[1]);
    printf("p[2] = %d\n", p[2]);

    free(p);

    return 0;
}
