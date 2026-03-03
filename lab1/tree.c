#include <stdlib.h>
#include "tree.h"
#include "linked_list.h"

void tree_destroy(TreeNode* node) {
    if (node == NULL) return;

    tree_destroy(node->left);
    tree_destroy(node->right);
    free(node);
}

TreeNode* create_node(int data) {
    TreeNode* node = malloc(sizeof(TreeNode));
    if (node == NULL) return NULL;

    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert(TreeNode** root, int data) {
    if (*root == NULL) {
        *root = create_node(data);
        return;
    }
    LinkedList queue;
    list_init(&queue);
    list_push_back(&queue, *root);

    while (!list_is_empty(&queue)) {
        TreeNode* current = list_pop_front(&queue);

        if (current->left == NULL) {
            current->left = create_node(data);
            list_destroy(&queue);
            return;
        } else {
            list_push_back(&queue, current->left);
        }

        if (current->right == NULL) {
            current->right = create_node(data);
            list_destroy(&queue);
            return;
        } else {
            list_push_back(&queue, current->right);
        }
    }
    list_destroy(&queue);
}

void find_min_helper(TreeNode* node, int depth, int* min_val, int* min_depth) {
    if (node == NULL) return;
    if (node->data < *min_val || (node->data == *min_val && depth < *min_depth)) {
        *min_val = node->data;
        *min_depth = depth;
    }
    find_min_helper(node->left, depth + 1, min_val, min_depth);
    find_min_helper(node->right, depth + 1, min_val, min_depth);
}

int find_min_depth(TreeNode* root) {
    if (root == NULL) return -1;
    int min_val = root->data;
    int min_depth = 0;

    find_min_helper(root, 0, &min_val, &min_depth);
    return min_depth;
}
