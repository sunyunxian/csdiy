#include <stdio.h>

void f(void);

int main(int argc, char const *argv[]) {
    printf("File name: %s\n", __FILE__);
    printf("Compiled on %s at %s\n", __DATE__, __TIME__);
    printf("Line number: %d\n", __LINE__);

    f();

    return 0;
}

void f(void) {
    printf("%s call\n", __func__);
    printf("%s end\n", __func__);
}
