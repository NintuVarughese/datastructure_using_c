//Demonstrate the data structure of adjacent matrix  using arrays
#include <stdio.h>

#define MAX_VERTICES 100

int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
int numVertices;

// Function to initialize the adjacency matrix
void initialize() {
    for (int i = 0; i < MAX_VERTICES; i++) {
        for (int j = 0; j < MAX_VERTICES; j++) {
            adjacencyMatrix[i][j] = 0;
        }
    }
}

// Function to add an edge between vertices u and v
void addEdge(int u, int v) {
    if (u < 0 || u >= numVertices || v < 0 || v >= numVertices) {
        printf("Invalid vertex index.\n");
        return;
    }
    adjacencyMatrix[u][v] = 1;
    adjacencyMatrix[v][u] = 1; // For undirected graphs
}

// Function to display the adjacency matrix
void display() {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    numVertices = 4;
    initialize();

    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(2, 3);

    display();

    return 0;
}


