#include <stdio.h>
#include <string.h>
#include "tree.h"

int main() {
    TreeNode* root = NULL;
    char command[50];
    int value;
    int min_depth;

    while(1) {
        scanf("%s", command);
        if (strcmp(command, "exit") == 0) {
            break;
        } else if (strcmp(command, "insert") == 0) {
            scanf("%d", &value);
            insert(&root, value);
        } else if (strcmp(command, "find_min") == 0) {
            min_depth = find_min_depth(root);
            printf("Depth of minimal value: %d.\n", min_depth);
        } else {
            printf("Unknown command.");
        }
    }
}
