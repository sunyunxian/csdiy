#include <assert.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int a = 5;
    assert(a == 5);
    puts("after assert success");

    a = 3;
    assert(a == 5);
    puts("after assert fail");

    return 0;
}
