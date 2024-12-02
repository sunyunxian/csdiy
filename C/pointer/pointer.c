#include <stdio.h>

void p1(void);
void p2(void);
void p3(void);
void p4(void);
int  main(void) {
    p1();
    p2();
    p3();
    p4();
    return 0;
}

void p1(void) {
    int  i = 0;
    int *p;
    p = &i;
    printf("i value: %d, i address: %p\n", i, &i);
    printf("(*p) value: %d, p value: %p\n", (*p), p);
}

void p2(void) {
    int  a = 10;
    int *p;
    p = &a;
    printf("a value: %d, a address: %p\n", a, &a);

    *p = 12;
    printf("a value: %d, a address: %p\n", a, &a);
}

void p3(void) {
    int  a = 10;
    int *p = &a;
    printf("Address p is %p\n", p);
    printf("Value at address p is %d\n", *p);
    printf("size of integer is %lu bytes\n", sizeof(int));
    printf("Address p + 1 is %p\n", p + 1);    // p + 1 = p + sizeof(int)，也就说指针的加减运算是按照 int 类型来算的
    printf("Value at address p is %d\n", *(p + 1));    // 这个会是一个垃圾值
}

void p4(void) {
    // 1025 二进制表示：100 0000 0001
    // int 假设需要 4 个 byte，那么需要补零，也就是：00000000 00000000 00000100 00000001
    int  a = 1025;
    int *p = &a;
    printf("size of integer is %lu bytes\n", sizeof(int));
    printf("address = %d, value = %d\n", p, *p);
    printf("address = %d, value = %d\n", p + 1, *(p + 1));

    char *c;
    c = (char *)p;    // 强制转换
    printf("size of integer is %lu bytes\n", sizeof(char));
    printf("address = %d, value = %d\n", c, *c);              // 00000001 值
    printf("address = %d, value = %d\n", c + 1, *(c + 1));    // 00000100 值
}
