#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent an element in the priority queue
struct QueueElement {
    int data;
    int priority;
};

// Array to store elements
struct QueueElement queue[MAX_SIZE];

// Variable to keep track of the size of the priority queue
int size = 0;

// Function to check if the priority queue is empty
int isEmpty() {
    return size == 0;
}

// Function to check if the priority queue is full
int isFull() {
    return size == MAX_SIZE;
}

// Function to enqueue (insert) an element into the priority queue
void enqueue(int data, int priority) {
    if (isFull()) {
        printf("Priority queue is full. Cannot enqueue.\n");
        return;
    }

    int i = size - 1;
    while (i >= 0 && queue[i].priority > priority) {
        queue[i + 1] = queue[i];
        i--;
    }

    queue[i + 1].data = data;
    queue[i + 1].priority = priority;

    size++;
}

// Function to dequeue (remove) an element from the priority queue
int dequeue() {
    if (isEmpty()) {
        printf("Priority queue is empty. Cannot dequeue.\n");
        return -1; // You can choose a different value to indicate an error.
    }

    int data = queue[0].data;
    for (int i = 1; i < size; i++) {
        queue[i - 1] = queue[i];
    }

    size--;
    return data;
}

// Function to display the elements in the priority queue
void display() {
    if (isEmpty()) {
        printf("Priority queue is empty.\n");
        return;
    }

    printf("Priority queue elements: ");
    for (int i = 0; i < size; i++) {
        printf("(%d, %d) ", queue[i].data, queue[i].priority);
    }
    printf("\n");
}

int main() {
    enqueue(10, 2);
    enqueue(20, 1);
    enqueue(30, 3);

    display();

    int item = dequeue();
    if (item != -1) {
        printf("Dequeued element: %d\n", item);
    }

    display();

    return 0;
}
