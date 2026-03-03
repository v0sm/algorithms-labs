#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
#include <stddef.h>

typedef struct TreeNode TreeNode;

typedef struct ListNode {
    TreeNode* data;
    struct ListNode *next;
} ListNode;

typedef struct {
    ListNode* head;
    ListNode* tail;
    size_t size;
} LinkedList;

void list_init(LinkedList* list);
void list_destroy(LinkedList* list);
void list_push_back(LinkedList* list, TreeNode* data);
TreeNode* list_pop_front(LinkedList* list);
bool list_is_empty(LinkedList* list);

#endif
