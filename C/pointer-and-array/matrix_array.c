#include <stdio.h>

int main(int argc, char const *argv[]) {
    // 访问二维数组
    int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int(*p)[3] = &matrix;    // (*p) 是因为优先级的问题
    printf("%p\n", p);

    // 数组指针
    int  a1[] = {1, 2}, a2[] = {3, 4}, a3[] = {5, 6};
    int *p1[3] = {a1, a2, a3};
    printf("p1[1][1] = %d\n", p1[1][1]);

    int  a[] = {1, 2, 3};
    int *ptr = a;
    printf("%d\n", ptr[1]);
    return 0;
}
