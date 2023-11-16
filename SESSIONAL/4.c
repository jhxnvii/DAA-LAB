#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Structure for adjacency list node
struct Node {
    int vertex;
    struct Node* next;
};

// Structure for the graph
struct Graph {
    int numVertices;
    struct Node* adjLists[MAX_VERTICES];
    bool visited[MAX_VERTICES];
};

// Function to create a new node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

// Function for DFS traversal
void DFS(struct Graph* graph, int vertex) {
    printf("%c, ", vertex + 'a'); // Assuming vertices are labeled as 'a', 'b', 'c', ...
    graph->visited[vertex] = true;

    struct Node* adjList = graph->adjLists[vertex];
    while (adjList != NULL) {
        int connectedVertex = adjList->vertex;
        if (!graph->visited[connectedVertex]) {
            DFS(graph, connectedVertex);
        }
        adjList = adjList->next;
    }
}

int main() {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = 5; // Assuming 5 vertices in the graph

    for (int i = 0; i < MAX_VERTICES; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = false;
    }

    // Add edges to the graph
    // Example: addEdge(graph, 0, 1); // Edge from vertex 0 to vertex 1

    char startVertex;
    printf("Select starting vertex: ");
    scanf(" %c", &startVertex); // Assuming input is in the format 'a', 'b', 'c', ...

    DFS(graph, startVertex - 'a'); // Assuming vertices are labeled as 'a', 'b', 'c', ...

    return 0;
}