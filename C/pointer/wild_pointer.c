#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    int  i = 1;
    int *p = &i;
    printf("p = %p\n", p);
    printf("*p = %d\n", *p);

    {
        p = malloc(sizeof(int));
        *p = 2;
        printf("p = %p\n", p);
        printf("*p = %d\n", *p);    // 该值是未定义的值
        free(p);
        // p = NULL;    // 指针 p 被释放后需要赋值为空指针，否则就是野指针了
    }
    printf("p = %p\n", p);
    printf("*p = %d\n", *p);    // p 指针因为被释放了，所以指向了未知的内存，就是是未定义的值

    return 0;
}
