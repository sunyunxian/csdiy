#include <stdio.h>
// #include "other_file_global_variable.c"

#define GLOBAL_MARCO 100    // 宏定义的全局替换

const int GLOBAL_CONST = 1;       // 不可变全局常量
int       global_variable = 2;    // 可变的全局常量，整个文件都可以被访问和修改
int       local_variable = 3;     // 一个和 main 函数内同名的变量，仅做演示

extern int other_file_global_variable;
// extern int other_file_static_global_variable;

void get_global_variable(void);
void static_variable(void);

int main(int argc, char const *argv[]) {
    int local_variable = 4;    // 本地变量，除了 main 函数内，其他都无法访问

    if (GLOBAL_CONST == 1) {
        printf("variable_global = %d\n", global_variable);    // 访问全局变量
        printf("local_variable = %d\n",
               local_variable);    // 代码块找不到会往上一层的 main 内找访问变量，如果还找不到会到全局找
        printf("other_file_global_variable = %d\n", other_file_global_variable);    // 访问外部文件的变量
    }

    get_global_variable();

    for (int i = 0; i < 5; i++) {
        static_variable();
    }
    ++other_file_global_variable;
    printf("other_file_global_variable = %d\n", other_file_global_variable);

    // ++other_file_static_global_variable;
    // printf("other_file_static_global_variable = %d\n", other_file_static_global_variable);

    return 0;
}

void get_global_variable(void) {
    printf("global_variable = %d\n", global_variable);
    printf("local_variable = %d\n", local_variable);    // 函数内没有声明，会往上找
}

void static_variable() {
    static int static_variable = 0;
    ++static_variable;
    printf("static int static_variable = %d\n", static_variable);
}
