#include <stdio.h>
#include <stdlib.h>

int *global_ptr;
int *global_use_local_address;

void function() {
    int local = 5;
    // local_ptr 和 local 被调用后会销毁，但是这个地址可能还存在，并且被使用
    // 这个就是悬挂指针
    int *local_ptr = &local;
    // 测试一下使用全局变量接收一个局部的指针
    global_use_local_address = local_ptr;
    printf("local_ptr = %d\n", *local_ptr);

    global_ptr = (int *)malloc(sizeof(int));

    if (!global_ptr) {
        exit(EXIT_FAILURE);
    } else {
        *global_ptr = 10;
        printf("*global_ptr = %d\n", *global_ptr);
    }
}

int main(int argc, char const *argv[]) {
    function();

    // 有可能还会访问到这个局部的地址，并且获取 value
    printf("global_use_local_address = %d\n", *global_use_local_address);

    printf("*global_ptr = %d\n", *global_ptr);
    // 释放后，global_ptr 就是悬挂指针了，不能被使用了
    free(global_ptr);
    // 再次访问，发现还能访问，但是 value 可能变了
    printf("*global_ptr = %d\n", *global_ptr);

    // 正确的做法是设置为 NULL，变成空指针，避免悬挂指针（如果 free 在中间的话）
    global_ptr = NULL;
    // 再次访问就会编译报错了，避免了悬挂指针的问题
    // 下面是无法正常编译的
    printf("*global_ptr = %d\n", *global_ptr);
    return 0;
}
