
#include "array_sequence_list.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {
    ArraySequenceList array_sequence_list;
    int               capacity = 1;
    init(&array_sequence_list, capacity);
    print(array_sequence_list);
    assert(array_sequence_list.capacity == 1);
    assert(array_sequence_list.length == 0);

    append(&array_sequence_list, 'l');
    append(&array_sequence_list, 'i');
    append(&array_sequence_list, 's');
    append(&array_sequence_list, 't');
    print(array_sequence_list);
    assert(array_sequence_list.capacity == 4);
    assert(array_sequence_list.length == 4);
    assert(strcmp(array_sequence_list.array, "list") == 0);

    assert(find(array_sequence_list, 'i') == 1);

    // printf("is empty = %d\n", is_empty(array_sequence_list));
    // set(&array_sequence_list, 0, 'L');
    // set(&array_sequence_list, 1, 'I');
    // set(&array_sequence_list, 2, 'S');
    // set(&array_sequence_list, 3, 'T');
    // print(array_sequence_list);
    // insert(&array_sequence_list, 0, 'A');
    // print(array_sequence_list);
    // get(array_sequence_list, 1);
    // delete (&array_sequence_list, 1);
    // delete (&array_sequence_list, 0);
    // print(array_sequence_list);
    // insert_element(&list, 1, 0);
    // insert_element(&list, 2, 1);
    // print_list(&list);
    // insert_element(&list, 3, 0);
    // print_list(&list);
    // destroy(&array_sequence_list);

    return 0;
}

int init(ArraySequenceList *array_sequence_list, int capacity) {
    array_sequence_list->array = (elements *)malloc(sizeof(elements) * capacity);

    if (array_sequence_list->array == NULL) {
        exit(EXIT_FAILURE);    // 初始化失败退出
    }
    array_sequence_list->capacity = capacity;    // 记录容量
    array_sequence_list->length = 0;             // 记录元素个数

    return 0;
}

int destroy(ArraySequenceList *array_sequence_list) {
    elements *element_ptr = array_sequence_list->array;
    printf("free element_ptr = %p\n", element_ptr);

    if (element_ptr == NULL) {
        // 分配失败了，这个时候需要看情况是否需要释放掉，目前我是释放掉的
        // 具体是否释放需要具体问题具体讨论
        free(array_sequence_list->array);
        exit(EXIT_FAILURE);
    } else {
        free(element_ptr);
    }
    return 0;
}

void print(ArraySequenceList array_sequence_list) {
    printf("capacity = %d, length = %d array_sequence_list = ", array_sequence_list.capacity,
           array_sequence_list.length);
    for (size_t i = 0; i < array_sequence_list.length; i++) {
        printf("%c ", array_sequence_list.array[i]);
    }
    printf("\n");
}

int length(ArraySequenceList array_sequence_list) { return array_sequence_list.length; }

int append(ArraySequenceList *array_sequence_list, elements element) {
    // 先检查内存是否够用，不够用就动态扩容，默认就是 2 倍扩容，
    // TODO 后续可以使用一种更高效的扩容算法
    if (array_sequence_list->capacity <= array_sequence_list->length) {
        // 扩容，realloc 直接赋值是不需要释放内存的
        array_sequence_list->array =
            (elements *)realloc(array_sequence_list->array, 2 * (array_sequence_list->capacity) * sizeof(elements));
        if (!array_sequence_list->array) {
            perror("relloc error");
            exit(EXIT_FAILURE);
        }
        // 更新容量
        array_sequence_list->capacity = 2 * array_sequence_list->capacity;
    }
    array_sequence_list->array[array_sequence_list->length] = element;
    array_sequence_list->length++;

    return 0;
}

int set(ArraySequenceList *array_sequence_list, int i, elements element) {
    // 对 i 进行一个判断
    if (i > array_sequence_list->capacity || i < 0) {
        perror("set i error");
        return 1;
    }
    // i 就是按照下标进行处理，也就是从 0 开始计算的，不用从 1 开始计算
    array_sequence_list->array[i] = element;

    return 0;
}

elements get(ArraySequenceList array_sequence_list, int i) {
    // 对 i 进行一个判断
    if (i > array_sequence_list.capacity || i < 0) {
        perror("set i error");
        return 1;
    }
    // 根据索引获取值
    printf("array_sequence_list %d = %c\n", i, array_sequence_list.array[i]);

    return array_sequence_list.array[i];
}

int clear(ArraySequenceList *array_sequence_list) {
    // 释放掉原有的内存
    if (array_sequence_list->array) {
        free(array_sequence_list->array);
        // 置空
        array_sequence_list->array = NULL;
    }
    // 重置长度为 0
    array_sequence_list->length = 0;
    // 重新申请内存
    array_sequence_list->array = (elements *)malloc(array_sequence_list->capacity * sizeof(elements));

    return 0;
}

int is_empty(ArraySequenceList array_sequence_list) { return array_sequence_list.length == 0; }

int insert(ArraySequenceList *array_sequence_list, int index, elements element) {
    // insert 不动态扩容
    if (index < 0 || index >= array_sequence_list->length) {
        perror("小于或者超出范围了");
        exit(EXIT_FAILURE);
    }
    // 插入索引的之前的都不用动，插入之后的索引，往后移动 1 位
    // 1 2 3 4 5，假设插入 index 2 值为 1，也就是 3 的位置，结果应该是 1 2 1 3 4 5
    for (int i = array_sequence_list->length; i >= 0; i--) {
        if (i < index) {
            // 插入索引之前的不动
            continue;
        }
        if (i == index) {
            array_sequence_list->array[index] = element;
        }
        if (i > index) {
            array_sequence_list->array[i] = array_sequence_list->array[i - 1];
        }
    }
    array_sequence_list->length++;

    return 0;
}

int delete(ArraySequenceList *array_sequence_list, int index) {
    if (index < 0 || index > array_sequence_list->length) {
        perror("小于或者超出范围了");
        exit(EXIT_FAILURE);
    }
    // 删除索引值，需要将该索引后面的值都往前移动 1 位，而索引前的值不需要动
    // 1 2 3 4 5，假设移除 3，也就是 index 2，结果应该是 1 2 4 5 NULL

    // 注意这里的是长度减 1，为了防止数组越界的问题
    for (size_t i = 0; i < array_sequence_list->length - 1; i++) {
        // 删除索引前的数据不处理
        if (i < index) {
            continue;
        }
        // 再增加一个控制条件，防止数组越界
        if (i >= index) {
            array_sequence_list->array[i] = array_sequence_list->array[i + 1];
        }
    }
    // 最后的索引重置为 '\0'
    array_sequence_list->array[array_sequence_list->length - 1] = '\0';
    // 修改长度
    array_sequence_list->length--;

    return 0;
}

int find(ArraySequenceList array_sequence_list, elements element) {
    // 查找索引并且返回找到的第一个的索引值
    for (size_t i = 0; i < array_sequence_list.length; i++) {
        if (array_sequence_list.array[i] == element) {
            return i;
        }
    }

    // 找不到就是 -1
    return -1;
}
