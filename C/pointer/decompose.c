#include <stdio.h>

void decompose(double x, long *, double *);

void decompose(double x, long *int_part, double *frac_part) {
    *int_part = (long)x;
    *frac_part = x - *int_part;
    printf("int_part = %ld, frac_part=%f\n", *int_part, *frac_part);
}
int main(void) {
    long   i = 0l;
    double d = 0.0;
    printf("i = %ld, d = %f\n", i, d);
    decompose(3.14159, &i, &d);
    printf("i = %ld, d = %f\n", i, d);
    return 0;
}
