#include <stdio.h>
#include "compare.h"
#include "sort.h"

int main(int argc, char const *argv[]) {
    int    array[] = {1, 3, 2};
    size_t length = sizeof(array) / sizeof(array[0]);
    size_t size = sizeof(array[0]);
    printf("%d %d\n", length, size);

    generic_sort(array, length, size, int_compare, NULL);

    for (size_t i = 0; i < length; i++) {
        printf("%d ", array[i]);
        printf("\n");
    }

    return 0;
}
