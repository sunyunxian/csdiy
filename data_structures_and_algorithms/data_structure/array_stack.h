/*
Stack ADT

0. init() 创建空栈
1. bool push(Stack *stack, elem_type element) 添加栈顶元素
2. elem_type pop(void) 删除栈顶元素，并返回删除的值（元素是销毁的）
3. int get_top(Stack *stack) 返回栈顶元素，不删除
4. bool is_empty(Stack *stack) 栈是否为空
5. int length(Stack *stack) 栈中的元素数量
6. bool destroy(Stack *stack) 销毁栈
*/

#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#include <stdint.h>
#include <stdbool.h>

#define element_type int
#define MAX_SIZE 1

typedef struct stack{
    element_type *elements;
    uint32_t top; // 栈顶元素索引，初始值为 -1，表示空栈
    uint32_t capacity; // 容量
}Stack;

Stack *init(void);
bool push(Stack *stack, element_type element); // 存在动态申请内存的情况，会返回 bool 值
void pop(Stack *stack);
element_type get_top(Stack *stack);
bool is_empty(Stack *stack);
uint32_t length(Stack *stack);
bool destroy(Stack *stack);
void traversal(Stack *stack);

#endif
