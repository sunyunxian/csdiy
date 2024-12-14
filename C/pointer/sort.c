#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

// 包装器
static int compare_warper(void *context, const void *a, const void *b) {
    printf("enter compare_warper\n");
    CompareFunc compare = (CompareFunc)context;
    return compare(a, b, NULL);
}

// TODO 没跑通，暂时没法解决，以后抽空处理一下泛型的问题
void generic_sort(void *array, size_t length, size_t size, CompareFunc compare, void *context) {
    printf("enter generic_sort\n");
    qsort_r(array, length, size, compare_warper, context);
}
