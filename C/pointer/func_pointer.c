#include <stdio.h>
#include <stdlib.h>

// typedef 返回值类型 (*新类型名)(参数列表); 这里的新类型名就是可以直接使用的
typedef int (*operation)(int, int);

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);

operation operations[4] = {add, subtract, multiply, divide};

// 定义一个回调函数
typedef void (*callback_func)(int element);

void get_setting(int *arr, int size, callback_func callback_func);
void print_element(int element);
void double_element(int element);

int main(int argc, char const *argv[]) {
    // 正常调用
    int a = 1, b = 2;
    int res = add(a, b);
    printf("res = %d\n", res);

    // 函数指针
    // 声明和定义
    int (*func_ptr)(int, int);
    // func_ptr -> int f(int num1, int num2);
    // 初始化和赋值
    func_ptr = add;
    // 使用：通过指针调用函数
    res = func_ptr(a, b);
    printf("res = %d\n", res);

    // 指针函数的主要用途就是回调函数
    // 回调函数允许一个函数接受一个函数参数，并在特定的事件下调用这个函数参数，
    // 使用数组调用对应的函数

    res = operations[0](a, b);
    res = operations[1](a, b);
    res = operations[2](a, b);
    res = operations[3](a, b);

    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    // 回调函数，使用了不同的 print_element double_element 的回调函数，实现了不同的功能
    // 或者根据不同的功能使用不同的回调函数，比如偶数就 print_element，奇数就是 double_element
    // 这样子可以实现更多的功能
    printf("callback print_element\n");
    get_setting(arr, size, print_element);

    printf("callback double_element\n");
    get_setting(arr, size, double_element);

    return 0;
}

int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return a / b; }

void get_setting(int *arr, int size, callback_func callback_func) {
    for (size_t i = 0; i < size; i++) {
        callback_func(arr[i]);
    }
}
void print_element(int element) { printf("%d\n", element); }

void double_element(int element) { printf("%d\n", element * 2); }
