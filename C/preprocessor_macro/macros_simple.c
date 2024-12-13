#include <stdio.h>

#define PI    3.1515
#define add   +
#define BEGIN {
#define END   }

int main(void) {
    printf("%d\n", (1 add 1));
    printf("%f\n", PI);
    if (1 == 1) BEGIN
    printf("Test BEGIN and END");
    END

        return 0;
}
