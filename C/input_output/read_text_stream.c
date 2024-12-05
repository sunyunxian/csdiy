#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "foo.txt"

int main(int argc, char const *argv[]) {
    printf("read file by line\n");
    // 设置缓冲区大小
    char buffer[256];
    // 打开文件，获取句柄
    FILE *fp = fopen(FILE_NAME, "r");

    // 错误处理
    if (fp == NULL) {
        printf("open file error\n");
        exit(EXIT_FAILURE);
    }
    // fgets 读取文件到缓冲区，按行读取
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }
    // 关闭文件
    if (fclose(fp) != 0) {
        printf("close file error");
        exit(EXIT_FAILURE);
    }

    printf("read file by character\n");
    // 重新的打开一个，使用字符读取模式
    fp = fopen(FILE_NAME, "r");
    // fgetc 按字符
    int ch;
    while ((ch = (fgetc(fp))) != EOF) {    // EOF 是按字符读取的边界条件
        putchar(ch);
    }

    // 关闭文件
    if (fclose(fp) != 0) {
        printf("close file error");
        exit(EXIT_FAILURE);
    }

    return 0;
}
