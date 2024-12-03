#include <stdio.h>

int find_max(int *array, int length);

int main(int argc, char const *argv[]) {
    int a[] = {1, 2, 3, 4, 3, 2, 1};

    int max = 0;
    max = find_max(a, sizeof(a) / sizeof(a[0]));
    printf("max = %d\n", max);

    return 0;
}

int find_max(int *array, int length) {
    int max = array[0];

    for (int i = 1; i < length; i++) {
        if (max < array[i]) {
            max = array[i];
        }
    }

    return max;
}
