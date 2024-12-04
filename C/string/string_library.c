#include <stdio.h>
#include <string.h>

void string_copy(void);
void string_length(void);
void string_splicing(void);
void string_comparison(void);

int main(void) {
    string_copy();

    string_length();

    string_splicing();

    string_comparison();

    return 0;
}

void string_copy(void) {
    // strcpy 字符串拷贝
    char str1[] = "str1";
    char str2[5];    // 假设长度为 5
    stpcpy(str2, str1);
    printf("str1 copy to str2: %s\n", str2);
}

void string_length(void) {
    // strlen，字符串长度，不包括 '\0'
    char str1[] = "str1";
    char str2[] = "str2 str2";
    printf("str1 length = %lu\n", strlen(str1));
    printf("str2 str2 length = %lu\n", strlen(str2));
}

void string_splicing(void) {
    // strcat 字符串拼接
    char str1[10] = "abc";
    strcat(str1, "123");
    printf("str1 strcat: %s\n", str1);
}

void string_comparison(void) {
    // strcmp 字符串比较
    char str1[] = "abc", str2[] = "abc", str3[] = "123";
    printf("str1 == str2: %d\n", strcmp(str1, str2));
    printf("str1 == str3: %d\n", strcmp(str1, str3));
}
