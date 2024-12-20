#include <stdbool.h>

#define MAX_SIZE 10

typedef int element_type ;

typedef struct queue{
    element_type *elements;
    int front; // 队列头
    int rear; // 队列尾
    int length; // 长度
    int capacity; // 容量
} Queue;

Queue *init(void); //  初始化
bool is_empty(Queue *queue); // 判断空值
int length(Queue *queue); // 长度
bool enqueue(Queue *queue, element_type element);// 入队，存在动态申请内存的情况，返回 bool 值
bool dequeue(Queue *queue); // 出队，存在空队列问题，返回 bool 值
element_type get_top(Queue *queue); // 队列头元素
element_type get_last(Queue *queue); // 队列末尾元素
bool clear(Queue *queue);
void traversal(Queue *queue);
bool destroy();
