#include <stdio.h>

/*
char const *argv[]
这种形式更直观地表达了 argv 是一个字符串数组
其中每个元素都是一个指向常量字符串的指针
这种表示方式与人们对命令行参数的直观理解更接近，即命令行参数是一组字符串。

char **argv
相对来说比较抽象，初看不太容易直接理解其含义，
需要对指针的指针有更深入的理解才能明白它实际上也是在表示一个字符串数组。
*/

int main(int argc, char const *argv[]) {
    printf("argc = %d\n", argc);
    for (size_t i = 0; i < argc; i++) {
        printf("argv[%zu] = %s\n", i, argv[i]);
    }

    return 0;
}
