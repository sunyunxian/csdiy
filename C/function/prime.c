#include <stdbool.h>
#include <stdio.h>

bool is_prime(int n);

int main(void) {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    if (is_prime(n))
        printf("%d is prime\n", n);
    else
        printf("%d is not prime\n", n);
    return 0;
}

bool is_prime(int n) {
    bool is_prime = true;
    for (int i = 2; i < n; i++) {
        if ((n % i) == 0) {
            is_prime = false;
            return is_prime;
        }
    }
    return is_prime;
}
