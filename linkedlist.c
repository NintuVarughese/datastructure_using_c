//Demonstrate the data structure of adjacent matrix  using linked lists
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in a linked list
struct Node {
    int vertex;
    struct Node* next;
};

// Structure to represent the adjacency list for a vertex
struct AdjList {
    struct Node* head;
};

// Structure to represent a graph with an array of adjacency lists
struct Graph {
    int numVertices;
    struct AdjList* array;
};

// Function to create a new node
struct Node* createNode(int vertex) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    if (graph == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    graph->numVertices = numVertices;

    graph->array = (struct AdjList*)malloc(numVertices * sizeof(struct AdjList));
    if (graph->array == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }

    for (int i = 0; i < numVertices; i++) {
        graph->array[i].head = NULL;
    }

    return graph;
}

// Function to add an edge to a graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    // For undirected graphs, you can add an edge from dest to src as well.
    newNode = createNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Function to display the graph
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node* current = graph->array[i].head;
        printf("Adjacency list of vertex %d:\n", i);
        while (current) {
            printf(" -> %d", current->vertex);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    int numVertices = 5;
    struct Graph* graph = createGraph(numVertices);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);

    return 0;
}





