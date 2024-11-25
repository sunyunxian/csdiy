#include <stdio.h>

int main(int argc, char const *argv[]) {
    float       f = 1.0f;
    double      d = 1.0;
    long double l = 1.0l;

    printf("f = %f\n", f);
    printf("d = %lf\n", d);
    printf("l = %Lf\n", l);

    printf("f = %e\n", f);
    printf("d = %le\n", d);
    printf("l = %Le\n", l);
    return 0;
}
