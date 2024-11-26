#include <stdint.h>
#include <stdio.h>

int main(int argc, char const *argv[]) {
    int32_t result = 0, prefix = 1, postfix = 1;

    printf("result = %d prefix = %d postfix = %d\n", result, prefix, postfix);

    result = ++prefix;
    printf("result = %d prefix = %d \n", result, prefix);

    result = 0;
    result = postfix++;
    printf("result = %d postfix = %d \n", result, postfix);    //
    return 0;
}
