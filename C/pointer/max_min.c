#include <stdio.h>
#define N 10

void max_min(int a[], int n, int *max, int *min);

int main(void) {
    int a[N], big, small;
    printf("Enter %d numbers: ", N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    max_min(a, N, &big, &small);
    printf("Largest %d\n", big);
    printf("Smallest %d\n", small);
    return 0;
}

void max_min(int a[], int n, int *max, int *min) {
    *max, *min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > *max) {
            *max = a[i];
        } else if (a[i] < *min) {
            *min = a[i];
        }
    }
}
