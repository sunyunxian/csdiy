#include "has_head_doubly_linked_list.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/*
还需要测试一下边界值的问题，比如最前、最后和空链表的情况，这里暂时不做讨论
*/
void test() {
    Node *head = (Node *)malloc(sizeof(Node));
    Node *first = (Node *)malloc(sizeof(Node));
    Node *middle = (Node *)malloc(sizeof(Node));
    Node *last = (Node *)malloc(sizeof(Node));

    head->prev = NULL;
    // head 元素暂时不存储任何数据
    head->element = 0;
    head->next = first;

    first->prev = head;
    first->element = 10;
    first->next = middle;

    middle->prev = first;
    middle->element = 20;
    middle->next = last;

    last->prev = middle;
    last->element = 30;
    last->next = NULL;
}

int main(int argc, char const *argv[]) {
    // test();
    Node *head = init_head();
    length(head);
    is_empty(head);
    insert_head(head, 3);
    insert_head(head, 2);
    insert_head(head, 1);
    insert_last(head, 4);
    insert_last(head, 5);
    insert_last(head, 6);
    search_node(head, 3);
    search_node(head, 10);
    traversal(head);
    delete_node(head, 2);
    traversal(head);
    delete_node(head, 6);
    traversal(head);
    length(head);
    is_empty(head);

    return 0;
}

Node *init_head(void) {
    // 初始化一个 head 即可，带头的数据不处理
    Node *head = (Node *)malloc(sizeof(Node));
    head->prev = NULL;
    head->next = NULL;
    return head;
}
void insert_head(Node *head, element_type element) {
    // 需要注意的是要维护前后 2 个节点
    // 创建要插入的新节点，并且初始化
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->element = element;
    // 因为有头节点，所以这些都是固定的
    new_node->prev = head;
    new_node->next = head->next;

    // 假设只有现在是插入第一个节点
    if (head->next != NULL) {
        head->next->prev = new_node;
    }
    head->next = new_node;
}
void insert_last(Node *head, element_type element) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->element = element;
    // 直接写死 NULL 也是可以的
    new_node->next = NULL;
    // 找到尾节点即可
    Node *last = head;
    while (last->next != NULL) {
        last = last->next;
    }
    // new_node->next = last->next;    // 其实也就是 NULL
    last->next = new_node;
    new_node->prev = last;
}
bool delete_node(Node *head, element_type element) {
    Node *temp;
    Node *pre = head;
    while (pre->next != NULL) {
        if (pre->next->element == element) {
            temp = pre->next;
            temp->prev->next = temp->next;
            // 如果不是最后一个，还需要处理一下前驱节点
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }
            // 如果是最后一个，那么除了把前一个 next 变成 NULL 其他的都不用管了
            free(temp);
            return true;
        }
        pre = pre->next;
    }
    return false;
}
Node *search_node(Node *head, element_type element) {
    // 找到就返回节点，找不到就返回一个空节点
    Node *temp = head;
    while (temp->next != NULL) {
        if (temp->next->element == element) {
            printf("search element = %d search to node = %p\n", element, temp);
            return temp;
        }
        temp = temp->next;
    }
    printf("search element = %d ", element);
    printf("search to node = %p, next pointer = %p\n", temp, temp->next);
    return temp->next;
}
bool is_empty(Node *head) {
    printf("is empty = %d\n", (head->next == NULL));
    return head->next == NULL;
}

void traversal(Node *head) {
    // 顺序遍历
    Node *temp = head;
    while (temp->next != NULL) {
        printf("%d->", temp->next->element);
        temp = temp->next;
    }
    printf("\n");
}
void reverse_traversal(Node *head) {
    //
}
int length(Node *head) {
    u_int32_t length = 0;
    Node     *temp = head;
    while (temp->next != NULL) {
        length += 1;
        temp = temp->next;
    }
    printf("length = %d\n", length);

    return length;
}
