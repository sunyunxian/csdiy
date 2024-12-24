#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

void sort(int *a, int length);
bool less(int v, int w);
void exch(int *a, int lo, int hi);
bool is_sorted(int *a, int lo, int hi);
void show(int *a, int length);

int main(int argc, char const *argv[]) {
    int a[] = {1, 1, 3, 2, 10, 8, 7, 10};
    int length = sizeof(a) / sizeof(a[0]);
    sort(a, length);
    show(a, length);

    return 0;
}

void sort(int *a, int length) {
    for (int i = 0; i < length; i++) {
        int low = i;
        for (int j = i + 1; j < length; j++) {
            if (less(a[j], a[low])) {
                low = j;
            }
        }
        exch(a, low, i);
        assert(is_sorted(a, 0, i) == true);
    }
}
bool less(int v, int w) { return v < w; }

void exch(int *a, int lo, int hi) {
    int swap = *(a + lo);
    *(a + lo) = *(a + hi);
    *(a + hi) = swap;
}

bool is_sorted(int *a, int lo, int hi) {
    for (int i = lo + 1; i <= hi; i++) {
        if (less(a[i], a[i - 1])) {
            return false;
        }
    }
    return true;
}

void show(int *a, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", *(a + i));
    }
    printf("\n");
}
