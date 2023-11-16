// BFS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

// Perform BFS and compute distances
void bfs(int** graph, int n, int start, int* distances) {
    bool visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
        distances[i] = -1;
    }
    struct Queue* queue = createQueue(n);

    visited[start] = true;
    distances[start] = 0;
    enqueue(queue, start);

    while (!isEmpty(queue)) {
        int node = dequeue(queue);
        for (int i = 0; i < n; i++) {
            if (graph[node][i] && !visited[i]) {
                visited[i] = true;
                distances[i] = distances[node] + 2;
                enqueue(queue, i);
            }
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int** graph = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--;
        v--;
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    int start;
    scanf("%d", &start);
    start--;

    int distances[n];
    bfs(graph, n, start, distances);

    printf("BFS Traversal:");
    for (int i = 0; i < n; i++) {
        if (i == start) continue;
        printf(" %d", distances[i]);
    }
    printf("\n");

    return 0;
}
