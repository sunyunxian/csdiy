#include <stdio.h>
#include <string.h>

#define DEBUG 1
#define LINUX

int main(int argc, char const *argv[]) {
    int i = 0, j = 1;
#if DEBUG
    printf("value of i: %d\n", i);
    printf("value of j: %d\n", j);
#endif

#if defined(WIN32)
    printf("defined WIN32");
#elif defined(MACOS)
    printf("Defined MACOS");
#elif defined(LINUX)
    printf("Defined LINUX");
#endif

    return 0;
}
