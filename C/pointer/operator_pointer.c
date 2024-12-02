#include <stdio.h>

int main(int argc, char const *argv[]) {
    int  i = 1;
    int *p;
    p = &i;

    printf("i = %d\n", i);
    printf("p = %p\n", p);
    printf("*p = %d\n", *p);

    printf("p+1 = %p\n", p + 1);
    printf("p-1 = %p\n", p - 1);

    printf("p+5 = %p\n", p + 5);
    printf("p-5 = %p\n", p - 5);

    return 0;
}
