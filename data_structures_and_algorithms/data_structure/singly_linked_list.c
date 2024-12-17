#include "singly_linked_list.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
/*
使用单链表实现顺序表，也叫 single_linked_list

链表的节点有 2 个数据：
1. 数据域，存储数据
2. 指针域，存储指向下一个节点的指针

单链表的第一个节点，也就是首节点
单链表的最后一个节点，也就是尾节点，指针域是指向 NULL 的

实现的 API
0. 初始化，返回头节点
1. 头插入，无返回
2. 尾插入，无返回
3. 删除，返回布尔值，是否成功
4. 查找，返回节点
5. 遍历，无返回，会打印
6. 长度，返回长度
7. 是否为空，返回布尔值，是否为空
*/

void test(void) {
    Node *head, *middle, *last;
    head = (Node *)malloc(sizeof(Node));
    middle = (Node *)malloc(sizeof(Node));
    last = (Node *)malloc(sizeof(Node));

    head->element = 10;
    middle->element = 20;
    last->element = 30;

    head->next = middle;
    middle->next = last;
    last->next = NULL;

    // 创建一个临时的变量指向 tmp，并把 head 地址分配给 tmp
    Node *tmp = head;
    while (tmp != NULL) {
        printf("%d ", tmp->element);
        tmp = tmp->next;
    }
    printf("\n");
}

int main(int argc, char const *argv[]) {
    Node *head = init_head();
    insert_head(&head, 3);
    insert_head(&head, 2);
    insert_head(&head, 1);
    insert_head(&head, 0);
    insert_last(&head, 1);
    insert_last(&head, 2);
    insert_last(&head, 3);
    insert_last(&head, 4);
    traversal(head);
    delete_node(&head, 1);
    traversal(head);
    Node *search_res = search_node(head, 4);
    printf("search_res->element = %d, search_res->next = %p\n", search_res->element, search_res->next);

    return 0;
}

Node *init_head(void) {
    Node *head = NULL;
    return head;
}

void insert_head(Node **head, element_type element) {
    // 头插法是 O(1)
    // 创建一个新 Node，并且赋值和
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->element = element;
    new_node->next = *head;
    // 把新的 new_node 设为头节点
    *head = new_node;
}

void insert_last(Node **head, element_type element) {
    // 尾插法是 O(N)
    // 创建一个新 Node，并且赋值和
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->element = element;
    new_node->next = NULL;    // 尾部插入很自然的 next 就是 NULL
    if (head == NULL) {       // 如果没有节点，那就是第一个节点了
        *head = new_node;
    } else {
        // 新建一个临时变量，并把头节点地址赋值给临时的变量，从头节点开始找是否是尾节点
        Node *last_node = *head;
        while (last_node->next != NULL) {
            last_node = last_node->next;    // 往下找
        }
        // 找到了尾节点，进行操作
        last_node->next = new_node;
    }
}

bool delete_node(Node **head, element_type key) {
    Node *tmp;

    // 第一个就是
    if ((*head)->element == key) {
        tmp = *head;
        *head = (*head)->next;
        free(tmp);
        return true;
    } else {
        // 创建一个遍历临时变量，并且指向 head 节点
        Node *pre = *head;
        // 开始从头遍历
        while (pre->next != NULL) {
            if (pre->next->element == key) {
                tmp = pre->next;
                pre->next = pre->next->next;
                free(tmp);
                return true;
            } else {
                pre = pre->next;
            }
        }
        return false;
    }
}

Node *search_node(Node *head, element_type key) {
    Node *temp = head;
    while (temp != NULL) {
        if (temp->element == key) {
            return temp;
        }
        temp = temp->next;
    }

    return NULL;
}

void traversal(Node *head) {
    while (head != NULL) {
        printf("%d->", head->element);
        head = head->next;
    }
    printf("\n");
}
