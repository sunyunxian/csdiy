#include <stdio.h>

int main(int argc, char const *argv[]) {
    char  c = 'a';
    char *p = &c;

    printf("size of char c = %lu\n", sizeof(c));
    printf("size of char pointer p = %lu\n", sizeof(p));

    return 0;
}
