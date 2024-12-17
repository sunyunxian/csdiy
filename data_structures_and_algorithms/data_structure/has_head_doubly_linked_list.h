#ifndef HAS_HEAD_DOUBLE_LINKED_LIST_H
#define HAS_HEAD_DOUBLE_LINKED_LIST_H

#include <stdbool.h>

#define element_type int

typedef struct node {
    element_type element;
    struct node *prev;
    struct node *next;
} Node;

Node *init_head(void);
void  insert_head(Node *head, element_type element);
void  insert_last(Node *head, element_type element);
bool  delete_node(Node *head, element_type element);
Node *search_node(Node *head, element_type element);
bool  is_empty(Node *head);
void  traversal(Node *head);
void  reverse_traversal(Node *head);
int   length(Node *head);

#endif
