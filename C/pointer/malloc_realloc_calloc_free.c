#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LEN   5
#define DYNAMIC_LEN 3

int main(int argc, char const *argv[]) {
    // 固定大小的数组
    printf("static array\n");
    static int arr[ARRAY_LEN] = {1, 2, 3, 4, 5};
    for (int i = 0; i < ARRAY_LEN; ++i) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    // 动态申请的数组
    // malloc 函数返回一个空指针类型 void*，其实就是泛型，这个类型可以赋值给任何类型的指针
    printf("dynamic array\n");
    // 申请的时候可以和下面的判断写在一起
    int *dynamic_arr = (int *)malloc(ARRAY_LEN * sizeof(int));
    // 需要对手动申请的内存进行判断，因为可能存在申请失败的情况
    // dynamic_arr == NULL 可以写成 !dynamic_arr
    if (!dynamic_arr) {
        printf("apply fail\n");
        exit(EXIT_FAILURE);
    }
    // malloc 申请的内存需要初始化
    for (int i = 0; i < ARRAY_LEN; ++i) {
        dynamic_arr[i] = i + 1;
    }
    // 使用数据
    for (int i = 0; i < ARRAY_LEN; ++i) {
        printf("dynamic_arr[%d] = %d\t", i, dynamic_arr[i]);
        printf("*(dynamic_arr + %d) = %d\n", i, *(dynamic_arr + i));
    }

    int *expand_dynamic_arr = (int *)realloc(dynamic_arr, (ARRAY_LEN + DYNAMIC_LEN) * sizeof(int));

    if (!expand_dynamic_arr) {
        printf("Apply fail\n");
        free(dynamic_arr);    // 需要释放
        exit(EXIT_FAILURE);
    }
    // 重新赋值
    dynamic_arr = expand_dynamic_arr;
    // 重新初始化
    dynamic_arr[5] = 100;
    dynamic_arr[6] = 200;
    dynamic_arr[7] = 300;

    printf("apply more size array\n");
    // 使用数据
    for (int i = 0; i < (ARRAY_LEN + DYNAMIC_LEN); ++i) {
        printf("dynamic_arr[%d] = %d\t", i, dynamic_arr[i]);
        printf("*(dynamic_arr + %d) = %d\n", i, *(dynamic_arr + i));
    }

    free(dynamic_arr);    // 释放内存

    // calloc 会初始化所有的数组成员都是 0
    int *calloc_arr = (int *)calloc(ARRAY_LEN, sizeof(int));

    if (!calloc_arr) {
        printf("Apply fail\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < ARRAY_LEN; ++i) {
        printf("calloc_arr[%d] = %d\t", i, calloc_arr[i]);
        printf("*(calloc_arr + %d) = %d\n", i, *(calloc_arr + i));
    }

    free(calloc_arr);

    return 0;
}
