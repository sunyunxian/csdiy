/*
使用 array 实现顺序表，也就是 arrayList
也可以叫 SequenceList

线性表连续春初空间可以使用静态的数组实现，也可以使用动态内存实现

静态数组：char data[100];
动态：char *data = (char *)malloc(N * sizeof(char))

*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef char elements;

typedef struct {
    elements *array;       // 动态空间的起始地址，指向了动态申请的堆内存
    int       capacity;    // 动态空间的可以容纳的元素个数，也就是容量
    int       length;      // 实际元素个数，也就是长度
} ArraySequenceList;

// 初始化传入的数据，并且给出初始化的大小
int  init(ArraySequenceList *array_sequence_list, int capacity);
int  free_array_sequence_list(ArraySequenceList *array_sequence_list);
void print(ArraySequenceList array_sequence_list);
int  length(ArraySequenceList array_sequence_list);
int  push_back(ArraySequenceList *array_sequence_list, elements element);
// 根据索引设置值
int set(ArraySequenceList *array_sequence_list, int i, elements element);
// 根据索引获取值
char get(const ArraySequenceList array_sequence_list, int i);

void insert_element(ArraySequenceList *array_sequence_list, elements element, int index) {    // index 约定从 0 开始
}
void delete_element(ArraySequenceList *array_sequence_list);

int main(int argc, char const *argv[]) {
    ArraySequenceList array_sequence_list;
    int               capacity = 1;
    init(&array_sequence_list, capacity);
    print(array_sequence_list);
    push_back(&array_sequence_list, 'l');
    push_back(&array_sequence_list, 'i');
    push_back(&array_sequence_list, 's');
    push_back(&array_sequence_list, 't');
    print(array_sequence_list);
    set(&array_sequence_list, 0, 'L');
    set(&array_sequence_list, 1, 'I');
    set(&array_sequence_list, 2, 'S');
    set(&array_sequence_list, 3, 'T');
    print(array_sequence_list);
    get(array_sequence_list, 1);

    // insert_element(&list, 1, 0);
    // insert_element(&list, 2, 1);
    // print_list(&list);
    // insert_element(&list, 3, 0);
    // print_list(&list);
    free_array_sequence_list(&array_sequence_list);

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

int free_array_sequence_list(ArraySequenceList *array_sequence_list) {
    elements *element_ptr = array_sequence_list->array;
    printf("element_ptr = %p\n", element_ptr);

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

int push_back(ArraySequenceList *array_sequence_list, elements element) {
    // 先检查内存是否够用，不够用就动态扩容，默认就是 2 倍扩容
    if (array_sequence_list->capacity <= array_sequence_list->length) {
        // 扩容
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

elements get(const ArraySequenceList array_sequence_list, int i) {
    // 对 i 进行一个判断
    if (i > array_sequence_list.capacity || i < 0) {
        perror("set i error");
        return 1;
    }
    // 根据索引获取值
    printf("array_sequence_list %d = %c\n", i, array_sequence_list.array[i]);

    return array_sequence_list.array[i];
}
