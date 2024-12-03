#include <stdio.h>

void fun(char *param);
void change_char_func(char *param);
void add_ten(u_int32_t *x);

int main(int argc, char const *argv[]) {
    u_int32_t i = 1;
    printf("i = %d\n", i);
    add_ten(&i);
    printf("i = %d\n", i);

    return 0;
}

void change_char_func(char *param) { *param = 'b'; }

void add_ten(u_int32_t *x) {
    u_int32_t ten = 10;
    *x = *x + ten;
}
