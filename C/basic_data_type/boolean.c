#include <stdbool.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    bool a = true;
    bool b = false;

    if (a) printf("a is true\n");
    if (!b) printf("b is false\n");

    printf("sizeof a = %lu\n", sizeof(a));
    return 0;
}
