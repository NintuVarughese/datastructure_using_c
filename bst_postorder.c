//Binary search tree insertion and display post-order without using recursion

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

typedef struct Node BSTNode;

typedef struct {
    BSTNode* stack[100];  // Stack for nodes, assuming a maximum of 100 nodes
    int top;
} Stack;

void initialize(Stack* stack) {
    stack->top = -1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, BSTNode* node) {
    if (stack->top < 99) {
        stack->stack[++stack->top] = node;
    } else {
        printf("Stack overflow.\n");
        exit(1);
    }
}

BSTNode* pop(Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->stack[stack->top--];
    } else {
        printf("Stack is empty.\n");
        exit(1);
    }
    return NULL;
}

void insert(BSTNode** root, int value) {
    if (*root == NULL) {
        BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));
        if (newNode == NULL) {
            printf("Memory allocation failed.\n");
            exit(1);
        }
        newNode->data = value;
        newNode->left = newNode->right = NULL;
        *root = newNode;
    } else {
        if (value < (*root)->data) {
            insert(&(*root)->left, value);
        } else {
            insert(&(*root)->right, value);
        }
    }
}

void postorderNonRecursive(BSTNode* root) {
    if (root == NULL) {
        return;
    }

    Stack stack;
    initialize(&stack);
    BSTNode* prev = NULL;

    do {
        while (root != NULL) {
            push(&stack, root);
            root = root->left;
        }

        while (root == NULL && !isEmpty(&stack)) {
            root = stack.stack[stack.top];
            if (root->right == NULL || root->right == prev) {
                printf("%d ", root->data);
                pop(&stack);
                prev = root;
                root = NULL;
            } else {
                root = root->right;
            }
        }
    } while (!isEmpty(&stack));
}

int main() {
    BSTNode* root = NULL;

    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 70);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 60);
    insert(&root, 80);

    printf("Postorder Traversal (Non-Recursive): ");
    postorderNonRecursive(root);
    printf("\n");

    return 0;
}

