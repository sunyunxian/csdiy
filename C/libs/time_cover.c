#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[]) {
    // 当前时间，时间戳
    time_t now = time(NULL);
    printf("timestamp = %lu\n", now);

    // 本地时间
    struct tm *local_time = localtime(&now);
    char       local_time_str[80];
    strftime(local_time_str, sizeof(local_time_str), "%Y-%m-%d %H:%M:%S", local_time);
    printf("local time = %s\n", local_time_str);

    // UTC 时间
    struct tm *utc_time = gmtime(&now);
    char       utc_time_str[80];
    strftime(utc_time_str, sizeof(utc_time_str), "%Y-%m-%d %H:%M:%S", utc_time);
    printf("utc time = %s\n", utc_time_str);

    return 0;
}
