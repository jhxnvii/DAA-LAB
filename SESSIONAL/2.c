#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum number of vertices in the graph
#define MAX_VERTICES 100

// Structure for the graph
struct Graph {
    int V; // Number of vertices
    int **adj; // Adjacency matrix
    int *visited; // Array to keep track of visited vertices in DFS
};

// Function to create a graph with V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;

    // Allocate memory for the adjacency matrix
    graph->adj = (int**)malloc(V * sizeof(int*));
    for (int i = 0; i < V; ++i) {
        graph->adj[i] = (int*)malloc(V * sizeof(int));
    }

    // Initialize the adjacency matrix
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            graph->adj[i][j] = 0;
        }
    }

    // Allocate memory for the visited array
    graph->visited = (int*)malloc(V * sizeof(int));

    return graph;
}

// Free the memory allocated for the graph
void freeGraph(struct Graph* graph) {
    for (int i = 0; i < graph->V; ++i) {
        free(graph->adj[i]);
    }
    free(graph->adj);
    free(graph->visited);
    free(graph);
}

// Queue structure for BFS
struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

bool isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

bool isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

void enqueue(struct Queue* queue, int item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue))
        return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

// Function for DFS traversal
void DFS(struct Graph* G, int u) {
    G->visited[u] = 1;
    printf("%d ", u);

    for (int v = 0; v < G->V; ++v) {
        if (G->adj[u][v] && !G->visited[v]) {
            DFS(G, v);
        }
    }
}

int main() {
    // Example usage
    int V = 5;
    struct Graph* graph = createGraph(V);

    // Assuming an undirected graph, add edges
    graph->adj[0][1] = graph->adj[1][0] = 1;
    graph->adj[0][2] = graph->adj[2][0] = 1;
    graph->adj[1][3] = graph->adj[3][1] = 1;
    graph->adj[2][4] = graph->adj[4][2] = 1;

    printf("DFS Traversal: ");
    DFS(graph, 0);

    // Don't forget to free the allocated memory
    freeGraph(graph);

    return 0;
}
