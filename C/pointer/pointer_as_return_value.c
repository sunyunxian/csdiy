#include <stdio.h>

int *max(int *a, int *b);

int main(void) {
    int a = 1, b = 2, *p;
    p = max(&a, &b);
    printf("p = %p, &b = %p\n", p, &b);
    printf("*p = %d", *p);
    return 0;
}

int *max(int *a, int *b) {
    if (*a > *b) {
        return a;
    } else {
        return b;
    }
}
