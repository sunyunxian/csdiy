#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <stdbool.h>

typedef int element_type;

typedef struct node {
    element_type element;
    struct node *next;
} Node;

Node *init_head(void);
void  insert_head(Node **head, element_type element);
void  insert_last(Node **head, element_type element);
bool  delete_node(Node **head, element_type key);
Node *search_node(Node *head, element_type key);
void  traversal(Node *head);

#endif
