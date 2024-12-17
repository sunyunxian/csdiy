#include "array_stack.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    /* code */
    Stack *stack = init();
    for (size_t i = 0; i < 20; i++) {
        push(stack, i);
    }
    traversal(stack);
    pop(stack);
    traversal(stack);

    return 0;
}

Stack *init() {
    Stack        *stack = (Stack *)malloc(sizeof(Stack));
    element_type *elements = (element_type *)malloc(sizeof(element_type));
    stack->elements = elements;
    stack->top = -1;
    stack->capacity = MAX_SIZE;

    return stack;
}

bool push(Stack *stack, element_type element) {
    // 动态扩容
    if (stack->top == stack->capacity - 1) {
        printf("扩容，从 %d-> %d\n", stack->capacity, stack->capacity * 2);
        stack->elements = (element_type *)realloc(stack->elements, (stack->capacity) * 2 * (sizeof(element_type)));
        stack->capacity = stack->capacity * 2;
    }

    stack->top++;    //
    stack->elements[stack->top] = element;

    // 先统一返回正确
    return true;
}
void pop(Stack *stack) {
    // 先不做检查
    stack->top--;
}
element_type get_top(Stack *stack) {
    // 先不做检查
    element_type ret = stack->elements[stack->top];
    return ret;
}

bool is_empty(Stack *stack) { return stack->top == -1; }

uint32_t length(Stack *stack) {
    uint32_t length = (stack->top) + 1;
    return length;
}

bool destroy(Stack *stack) {
    free(stack);
    stack = NULL;

    return 0;
}

void traversal(Stack *stack) {
    u_int32_t length = stack->top + 1;
    printf("length = %d ->", length);
    //
    for (size_t i = 0; i < length; i++) {
        printf("%d ", stack->elements[i]);
    }
    printf("\n");
}
