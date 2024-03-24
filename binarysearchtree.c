#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the binary search tree
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a value into the binary search tree
struct TreeNode* insert(struct TreeNode* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to search for a value in the binary search tree
struct TreeNode* search(struct TreeNode* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    } else if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Function to traverse the binary search tree in inorder manner
void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct TreeNode* root = NULL;
    
    // Insert some values into the binary search tree
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 7);
    root = insert(root, 12);
    
    // Print the inorder traversal of the binary search tree
    printf("Inorder traversal of the binary search tree: ");
    inorderTraversal(root);
    printf("\n");
    
    // Search for a value in the binary search tree
    int valueToSearch = 7;
    struct TreeNode* result = search(root, valueToSearch);
    if (result != NULL) {
        printf("%d found in the binary search tree.\n", valueToSearch);
    } else {
        printf("%d not found in the binary search tree.\n", valueToSearch);
    }
    
    return 0;
}
