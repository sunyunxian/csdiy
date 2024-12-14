#include <stdarg.h>
#include <stdio.h>

/*
可变参数非常重要，
虽然可以传递一个数组解决参数的个数问题，但是太麻烦了，还要遍历数组进行处理
使用 ... 语法可以使用可变参数的特性
num_args 就是参数的个数，而后面的 ... 就是具体的参数
#include <stdarg.h> 这个宏里支持可变参数，需要引入
里面有 4 个宏

va_start
va_arg
va_end
va_copy

*/
double average(int num_args, ...);

int main(int argc, char const *argv[]) {
    printf("average(1, 2, 3, 4, 5) = %.2f\n", average(5, 1, 2, 3, 4, 5));

    return 0;
}

double average(int num_args, ...) {
    double sum = 0.0;
    // 固定的写法，等于把所有的可变参数变成了 va_list
    va_list args;
    // 固定写法，开始读取
    va_start(args, num_args);
    for (size_t i = 0; i < num_args; i++) {
        // va_arg 获取下一个参数
        sum += va_arg(args, int);
    }
    // 固定写法，结束了
    va_end(args);

    return num_args > 0 ? sum / num_args : 0;
}
