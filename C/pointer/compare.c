#include "compare.h"
#include <stdio.h>
#include <string.h>

int int_compare(const void *a, const void *b, void *context) {
    (void)context;
    printf("enter int_compare");

    return (*(int *)a - *(int *)b);
}

int float_compare(const void *a, const void *b, void *context) {
    (void)context;
    const float *float_a = (const float *)a;
    const float *float_b = (const float *)b;

    if (*float_a > *float_b) return 1;
    if (*float_a < *float_b) return -1;

    return 0;
}

int string_compare(const void *a, const void *b, void *context) {
    (void)context;
    const char *char_a = *(const char **)a;
    const char *char_b = *(const char **)b;

    return strcmp(char_a, char_b);
}
