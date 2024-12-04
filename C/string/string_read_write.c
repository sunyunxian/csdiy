#include <stdio.h>

#define STR_LEN 10

void write_string_by_printf(void);
void write_string_by_puts(void);
void read_string_by_scanf(void);
// void read_string_by_gets(void);
int read_line_by_getchar(char str[], int n);

int main(void) {
    write_string_by_printf();
    write_string_by_puts();
    read_string_by_scanf();
    // read_string_by_gets();
    char str[STR_LEN];
    read_line_by_getchar(str, STR_LEN - 1);
    return 1;
}

void write_string_by_printf(void) {
    printf("Read string\n");
    char str[] = "read string by printf";
    printf("%s\n", str);
    printf("%.6s\n", str);
    printf("%10s\n", str);
    printf("%10.6s\n", str);
    printf("%-10.6s\n", str);
}

void write_string_by_puts() {
    char str[] = "read string by puts";
    puts(str);    // puts 自带换行
}

void read_string_by_scanf(void) {
    char sentence[100];    // demo 假设长度是 100
    printf("Enter a sentence: \n");
    // To c, or not to c: that is the question.
    scanf("%s", sentence);
    printf("Your enter: %s", sentence);    // 输出结果是 To，碰到空格会停止调用
}

// void read_string_by_gets(void)
// {
//     // 不安全的方法，已经弃用了
//     char sentence[100];
//     printf("Enter a sentence: \n");
//     // To c, or not to c: that is the question.
//     gets(sentence);
//     printf("Your enter: %s", sentence);
// }

int read_line_by_getchar(char str[], int n) {
    int ch, i = 0;
    while ((ch = getchar()) != '\n') {
        if (i < n) {
            str[i++] = ch;
        }
    }
    str[i] = '\0';
    printf("%s\n", str);
    return i;
}
