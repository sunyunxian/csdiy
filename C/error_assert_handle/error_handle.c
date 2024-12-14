#include <errno.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    // 模拟一个错误
    errno = 1;
    int y = sqrt(1);
    if (errno != 0) {
        fprintf(stderr, "sqrt error; program terminated.\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}
