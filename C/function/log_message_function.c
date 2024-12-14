#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum { LOG_INFO, LOG_WARNING, LOG_ERROR } LogLevel;

const char* get_current_time();

// 可变参数
void log_message(LogLevel level, const char* format, ...);

int main(int argc, char const* argv[]) {
    log_message(LOG_INFO, "loginfo msg");
    log_message(LOG_WARNING, "logwarning msg");
    log_message(LOG_ERROR, "logerror msg");

    return 0;
}
const char* get_current_time() {
    static char buffer[20];
    time_t      now = time(NULL);
    struct tm*  tm_info = localtime(&now);
    strftime(buffer, 20, "%Y-%m-%d %H:%M:%S", tm_info);

    return buffer;
}
void log_message(LogLevel level, const char* format, ...) {
    const char* level_str;
    switch (level) {
        case LOG_INFO:
            level_str = "INFO";
            break;
        case LOG_WARNING:
            level_str = "WARNING";
            break;
        case LOG_ERROR:
            level_str = "ERROR";
            break;
        default:
            level_str = "UNKNOWN";
            break;
    }
    printf("[%s] [%s]", get_current_time(), level_str);

    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);

    printf("\n");
}
