#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "foo.txt"

int main(int argc, char const *argv[]) {
    FILE *fp;
    if ((fp = fopen(FILE_NAME, "w")) == NULL) {
        printf("open file error\n");
        exit(EXIT_FAILURE);
    }
    putc('a', fp);
    putc('b', fp);
    putc('\n', fp);

    fclose(fp);

    return 0;
}
