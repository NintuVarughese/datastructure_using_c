//Binary search tree insertion using names and display the names in ascending order using inorder traversal.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[100];
    struct Node* left;
    struct Node* right;
};

typedef struct Node BSTNode;

void insert(BSTNode** root, char* name) {
    if (*root == NULL) {
        BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            exit(1);
        }
        strcpy(newNode->name, name);
        newNode->left = newNode->right = NULL;
        *root = newNode;
    } else {
        int cmp = strcmp(name, (*root)->name);
        if (cmp < 0) {
            insert(&(*root)->left, name);
        } else {
            insert(&(*root)->right, name);
        }
    }
}

void inorderTraversal(BSTNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%s\n", root->name);
        inorderTraversal(root->right);
    }
}

int main() {
    BSTNode* root = NULL;

    insert(&root, "Alice");
    insert(&root, "Bob");
    insert(&root, "Charlie");
    insert(&root, "David");
    insert(&root, "Eve");

    printf("Names in Ascending Order (Inorder Traversal):\n");
    inorderTraversal(root);

    return 0;
}


