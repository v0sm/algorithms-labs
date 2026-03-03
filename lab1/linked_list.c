#include <stdlib.h>
#include "linked_list.h"

void list_init(LinkedList* list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

void list_destroy(LinkedList* list) {
    if (list == NULL) return;

    ListNode* current = list->head;
    while(current != NULL) {
        ListNode* temp = current;
        current = current->next;
        free(temp);
    }
    
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

void list_push_back(LinkedList* list, TreeNode* data) {
    if (list == NULL || data == NULL) return;

    ListNode* node = malloc(sizeof(ListNode));
    if (node == NULL) return;

    node->data = data;
    node->next = NULL;

    if (list->head == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }

    list->size++;
}

TreeNode* list_pop_front(LinkedList* list) {
    if (list == NULL || list->head == NULL) return NULL;
    
    ListNode* to_delete = list->head;
    TreeNode* data = to_delete->data;
    
    list->head = list->head->next;
    if (list->head == NULL) {
        list->tail = NULL;
    }
    
    free(to_delete);
    list->size--;
    return data;
}

bool list_is_empty(LinkedList* list) {
    return list == NULL || list->head == NULL;
}