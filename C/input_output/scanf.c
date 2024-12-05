#include <stdio.h>

int main(int argc, char const *argv[]) {
    int number;
    int rst = scanf("%d", &number);

    if (rst >= 1) {
        printf("number = %d\n", number);
    } else if (rst == EOF) {    // ctrl + d 会发送一个 EOF 的 input，EOF 其实是 (-1) 的宏
        printf("end\n");
    } else {
        printf("know type, error\n");
    }

    return 0;
}
