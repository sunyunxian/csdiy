// Prints a bad pun
#include <stdio.h>

void   print_pun(void);                      // 空返回值，空参数
void   print_custom(char *custom_string);    // 空返回值，有参数
double average(double x, double y);          // 有参数，有返回值

int main(void) {
    print_pun();

    print_custom("print custom string");

    printf("(10.0 + 20.0) / 2 = %.1lf\n", average(10.0, 20.0));

    return 0;
}

void   print_pun(void) { printf("To C, or not to C: that  is the question.\n"); }
void   print_custom(char *print_custom) { printf("%s\n", print_custom); }
double average(double x, double y) { return (x + y) / 2; }
