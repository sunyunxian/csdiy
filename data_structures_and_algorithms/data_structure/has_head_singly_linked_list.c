#include "has_head_singly_linked_list.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/*
单链表区分带 head 和不带 head 的 2 种

这里实现的是带 head 的单链表

区别在于不带 head 第一个 node 就是 head
而带 head 的会用 head 指向第一个 node，同时 head 可能会存储额外的数据，比如长度数据

这里会记录长度

实现的 API
0. 初始化，返回头节点
1. 头插入，无返回
2. 尾插入，无返回
3. 按值删除，返回布尔值，是否成功
4. 查找，返回节点
5. 遍历，无返回，会打印
6. 长度，返回长度
7. 是否为空，返回布尔值，是否为空

可选实现
1. 指定位置插入（insertAtIndex，可选操作，根据具体需求实现）
2. 按索引删除（deleteAtIndex，可选操作）
3. 销毁链表操作（destroyList）
4. 所有的匹配节点、反向遍历、合并链表、反转数组... 还有更多的操作暂时不讨论
*/

void test(void) {
    Node *head, *first, *middle, *last;
    head = (Node *)malloc(sizeof(Node));
    first = (Node *)malloc(sizeof(Node));
    middle = (Node *)malloc(sizeof(Node));
    last = (Node *)malloc(sizeof(Node));

    first->element = 10;
    middle->element = 20;
    last->element = 30;

    head->next = first;
    first->next = middle;
    middle->next = last;
    last->next = NULL;

    // 创建一个临时的变量指向 tmp，并把 head 地址分配给 tmp
    // 如果没有 head 那么就需要把 tmp 指向 head，而现在有了 head 只要指向 head->next
    Node *tmp = head->next;
    while (tmp != NULL) {
        printf("%d ", tmp->element);
        tmp = tmp->next;
    }
    printf("\n");
}

int main(int argc, char const *argv[]) {
    // test();
    Node *head = init_head();
    printf("is empty = %d\n", is_empty(head));
    insert_head(head, 3);
    insert_head(head, 2);
    insert_head(head, 1);
    insert_head(head, 0);
    insert_last(head, 1);
    insert_last(head, 2);
    insert_last(head, 3);
    insert_last(head, 4);
    traversal(head);
    length(head);
    delete_node(head, 1);
    traversal(head);
    length(head);
    Node *searched = search_node(head, 2);
    printf("searched.element = %d\n", searched->element);
    // delete_node(&head, 1);
    // traversal(head);
    // Node *search_res = search_node(head, 4);
    // printf("search_res->element = %d, search_res->next = %p\n", search_res->element, search_res->next);

    return 0;
}

Node *init_head(void) {
    // 带头结点的会申请内存地址，而不是一个 NULL
    Node *head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    head->element = 0;

    return head;
}

bool is_empty(Node *head) { return head->next == NULL; }

void insert_head(Node *head, element_type element) {
    // 头插法是 O(1)
    // 创建一个新 Node，并且赋值初始化
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->element = element;
    // 空链表的情况
    new_node->next = head->next;
    head->next = new_node;

    head->element++;
}

void insert_last(Node *head, element_type element) {
    // 创建一个新 Node，并且赋值和
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->element = element;
    new_node->next = NULL;

    Node *last_node = head;
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }
    last_node->next = new_node;

    head->element++;
}

bool delete_node(Node *head, element_type key) {
    Node *tmp;

    // 建立一个遍历的节点，并且把 head 的赋值给这个节点
    Node *pre = head;
    // 拿到 next 开始遍历，直到为空则遍历结束，中间判断是否成功即可
    // 成功就终止，失败最后返回 false
    // pre->next 就是 first 节点
    while (pre->next != NULL) {
        if (pre->next->element == key) {
            // 临时存储需要被删除的节点地址
            tmp = pre->next;
            //
            pre->next = pre->next->next;
            free(tmp);
            return true;
        } else {
            pre = pre->next;
        }
    }
    return false;
}

Node *search_node(Node *head, element_type key) {
    Node *temp = head;
    while (temp->next != NULL) {
        if (temp->element == key) {
            return temp;
        }
        temp = temp->next;
    }

    return NULL;
}

void traversal(Node *head) {
    // 带 head 的不会打印，所以会跳过这个
    while (head->next != NULL) {
        printf("%d—>", head->next->element);
        head = head->next;
    }
    printf("\n");
}

int length(Node *head) {
    // 一种是累计器
    u_int32_t length = 0;

    Node *temp = head;
    while (temp->next != NULL) {
        length++;
        temp = temp->next;
    }

    // 直接使用 head 中的累加器
    // u_int32_t length = head->element;
    printf("length = %d\n", length);

    return length;
}
