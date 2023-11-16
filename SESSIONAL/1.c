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


// Function for DFS traversal
void DFS(struct Graph *G, int u) {
    G->visited[u] = 1;
    printf("%d ", u);

    for (int v = 0; v < G->V; ++v) {
        if (G->adj[u][v] && !G->visited[v]) {
            DFS(G, v);
        }
    }
}

int main(){
int dfs array ={a,b,e,f,c,d}
implement dfs algorithm for the graph given below . you can find the graph below. the program should work for any strating vertex. tiebreakers should be handled based on lexicographical
order . write a code in c.
sample input = select starting vertex a 
sample output = a, b ,e, f, c, d 




}



