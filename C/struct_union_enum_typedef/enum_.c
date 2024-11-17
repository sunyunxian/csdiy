#include <stdio.h>

enum status { low = 1, middle = 2, high = 3 };

int main(int argc, char const *argv[]) {
    enum status x = low;
    if (x == low) {
        printf("x == low\n");
    }
    return 0;
}
