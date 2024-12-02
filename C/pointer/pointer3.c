#include <stdio.h>

int main(void) {
    int i, *p, *q;
    p = &i;    // pointer assignment
    printf("i = %d, *p = %d, p = %p\n", i, *p, p);
    q = p;    // pointer assignment
    printf("i = %d, *p = %d, p = %p, *q = %d, q = %p\n", i, *p, p, *q, q);
    *p = 1;
    printf("i = %d, *p = %d, p = %p, *q = %d, q = %p\n", i, *p, p, *q, q);
    *q = 2;
    printf("i = %d, *p = %d, p = %p, *q = %d, q = %p\n", i, *p, p, *q, q);
    return 0;
}
