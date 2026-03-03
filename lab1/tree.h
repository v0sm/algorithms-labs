#ifndef TREE_H
#define TREE_H

typedef struct TreeNode{
    struct TreeNode *left;
    struct TreeNode *right;
    int data;
} TreeNode;

void tree_destroy(TreeNode* node);
TreeNode* create_node(int data);
void insert(TreeNode** root, int data);
void find_min_helper(TreeNode* node, int depth, int* min_val, int* min_depth);
int find_min_depth(TreeNode* root);

#endif
