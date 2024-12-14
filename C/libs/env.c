#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
    // 读取环境变量
    const char *path = getenv("PATH");
    if (path) {
        printf("PATH:%s\n", path);
    } else {
        exit(EXIT_FAILURE);
    }
    // 写入环境变量
    char *env_str = "MY_ENV_VAR=foo";

    if (putenv(env_str) == 0) {
        char *value = getenv("MY_ENV_VAR");
        if (value != NULL) {
            printf("MY_ENV_VAR = %s\n", value);
        }
    } else {
        perror("putenv");
        return EXIT_FAILURE;
    }

    return 0;
}
