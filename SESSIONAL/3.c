#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// Stack structure for DFS
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

bool isStackEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

bool isStackFull(struct Stack* stack) {
    return (stack->top == stack->capacity - 1);
}

void push(struct Stack* stack, int item) {
    if (isStackFull(stack))
        return;
    stack->array[++stack->top] = item;
}

int pop(struct Stack* stack) {
    if (isStackEmpty(stack))
        return -1;
    return stack->array[stack->top--];
}

// Function for DFS traversal
void DFS(struct Graph* G, int start) {
    struct Stack* stack = createStack(G->V);

    G->visited[start] = 1;
    push(stack, start);

    while (!isStackEmpty(stack)) {
        int current = pop(stack);
        printf("%d ", current);

        for (int v = G->V - 1; v >= 0; --v) {
            if (G->adj[current][v] && !G->visited[v]) {
                G->visited[v] = 1;
                push(stack, v);
            }
        }
    }

    free(stack);
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

    printf("DFS Traversal starting from vertex 0: ");
    DFS(graph, 0);

    // Don't forget to free the allocated memory
    freeGraph(graph);

    return 0;
}
