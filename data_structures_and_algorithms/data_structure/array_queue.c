#include "array_queue.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
    Queue *queue = init();
    is_empty(queue);
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    is_empty(queue);
    traversal(queue);
    dequeue(queue);
    traversal(queue);
    dequeue(queue);
    dequeue(queue);
    traversal(queue);
    is_empty(queue);

    return 0;
}

Queue *init(void) {
    element_type *elements = (element_type *)malloc(MAX_SIZE * sizeof(element_type));
    Queue        *init_queue = (Queue *)malloc(sizeof(Queue));
    init_queue->length = 0;
    // front 和 rear 可以从 0 开始标识空，也可以用一个特殊的 -1 值标识空
    init_queue->front = 0;
    init_queue->rear = 0;
    init_queue->capacity = MAX_SIZE;
    init_queue->elements = elements;

    return init_queue;
}
bool is_empty(Queue *queue) {
    if (queue->rear == 0 || (queue->rear != 0 && queue->front == queue->rear)) {
        printf("空\n");
        return true;
    }

    return false;
}
int length(Queue *queue) {
    // 暂时不用实现
    return 1;
}

element_type get_top(Queue *queue) {
    // 暂时忽略异常处理
    return queue->elements[queue->front];
}
element_type get_rear(Queue *queue) {
    // 暂时忽略一场处理
    return queue->elements[queue->rear - 1];
}
bool enqueue(Queue *queue, element_type element) {
    if (queue->capacity == queue->rear) {
        perror("队列已满");
        return false;
        // exit(EXIT_FAILURE);
    } else {
        queue->elements[queue->rear] = element;
        queue->rear++;
    }

    return true;
}
bool dequeue(Queue *queue) {
    if (queue->capacity == queue->rear) {
        perror("队列为空");
        return false;
    } else {
        printf("出队元素：%d\n", queue->elements[queue->front]);
        queue->front++;
    }
    return true;
}

void traversal(Queue *queue) {
    printf("queue: ");
    for (size_t i = queue->front; i < queue->rear; i++) {
        printf("%d<-", queue->elements[i]);
    }
    printf("\n");
}

bool clear(Queue *queue) {
    // 清理
    queue->front = 0;
    queue->rear = 0;

    return true;
}
