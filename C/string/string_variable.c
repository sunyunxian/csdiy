#include <stdio.h>

#define STR_LEN 80

void init_string(void);
void string_diff_array(void);

int main(void) {
    init_string();
    string_diff_array();
    return 1;
}

void init_string(void) {
    printf("Init string variable\n");

    // 使用宏定义 string 长度
    char str[STR_LEN + 1];
    printf("%s\n", str);

    // 正确的初始化方式，字符串的长度 + 1
    char date[8] = "June 14";
    printf("%s\n", date);

    // 长度大于字符串长度，那么会被额外的填充 \0
    char date1[9] = "June 14";
    printf("%s\n", date1);

    // 长度小于字面串初始化器，也可以初始化，但是是不合法的
    char date2[7] = "June 14";
    printf("%s\n", date2);

    // 不声明长度，这个是比较常用的一个方式，编译器会自动推导，特别是字符串比较长的时候
    char date3[] = "June 14";
    printf("%s\n", date3);
}

void string_diff_array(void) {
    printf("String diff array\n");

    // 数组形式
    char data[] = "June 14";
    for (int i = 0; i < (int)(sizeof(data) / sizeof(data[0])); i++) {
        printf("%c\n", data[i]);
    }

    // 指针形式
    char *p = "June 14";
    for (int i = 0; i < 7; ++i) {
        // 可以当成数组使用
        printf("%c ", p[i]);
        // 当成指针使用
        printf("%c\n", *(p + i));
    }
}
