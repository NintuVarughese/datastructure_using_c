#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node queue;

queue* f = NULL;
queue* r = NULL;

void enqueue(int e) {
    queue* t = (queue*)malloc(sizeof(queue));
    t->data = e;
    t->next = NULL;

    if (f == NULL) {
        f = t;
        r = t;
    } else {
        r->next = t;
        r = t;
    }
}

void dequeue() {
    if (f == NULL) {
        printf("\nLinked queue is empty");
    } else {
        printf("\n%d", f->data);
        queue* temp = f;
        f = f->next;
        free(temp);

        if (f == NULL) {
            r = NULL;
        }
    }
}

int menu() {
    int ch;
    printf("\nQueue Menu\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);
    return ch;
}

void processQueue() {
    int ch;
    for (ch = menu(); ch != 3; ch = menu()) {
        switch (ch) {
            case 1:
                printf("Enter the element: ");
                scanf("%d", &ch);
                enqueue(ch);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

int main() {
    processQueue();
    return 0;
}










