#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the circular linked list
struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        newNode->next = newNode;  // Make it point to itself
        return newNode;
    }

    newNode->next = head->next;
    head->next = newNode;

    return head;
}

// Function to delete a node by value from the circular linked list
struct Node* deleteNode(struct Node* head, int value) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return head;
    }

    struct Node* current = head;
    struct Node* prev = NULL;

    do {
        if (current->data == value) {
            if (prev != NULL) {
                prev->next = current->next;
            } else if (current == head) {
                if (current->next == current) {
                    free(current);
                    return NULL;
                }
                head = current->next;
            }
            free(current);
            printf("Node with value %d deleted.\n", value);
            return head;
        }
        prev = current;
        current = current->next;
    } while (current != head);

    printf("Node with value %d not found.\n", value);
    return head;
}

// Function to search for a value in the circular linked list
int searchNode(struct Node* head, int value) {
    if (head == NULL) {
        return 0;
    }

    struct Node* current = head;
    do {
        if (current->data == value) {
            return 1;  // Value found
        }
        current = current->next;
    } while (current != head);

    return 0;  // Value not found
}

// Function to display the circular linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* current = head;
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("...\n");
}

int main() {
    struct Node* head = NULL;
  head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 30);
    printf("Circular Linked List: ");
    displayList(head);
    int searchValue = 20;
    if (searchNode(head, searchValue)) {
        printf("Value %d found in the list.\n", searchValue);
    } else {
        printf("Value %d not found in the list.\n", searchValue);
    }
    int deleteValue = 20;
    head = deleteNode(head, deleteValue);
    printf("Updated Circular Linked List: ");
    displayList(head);
    return 0;
}
