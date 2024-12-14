#ifndef SORT_H
#define SORT_H

#include <stddef.h>

// context 是预留参数
typedef int (*CompareFunc)(const void *, const void *, void *context);

void generic_sort(void *array, size_t length, size_t size, CompareFunc compare, void *context);

#endif
