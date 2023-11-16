#include <stdio.h>
#include <stdlib.h>

// Structure to represent a symbol (alphabet and its frequency)
struct SYMBOL {
    char alphabet;
    int frequency;
};

// Structure to represent a node in the Huffman tree
struct Node {
    struct SYMBOL symbol;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(struct SYMBOL symbol) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->symbol = symbol;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to swap two SYMBOLs
void swap(struct SYMBOL* a, struct SYMBOL* b) {
    struct SYMBOL temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform min-heapify
void minHeapify(struct SYMBOL arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].frequency < arr[smallest].frequency)
        smallest = left;

    if (right < n && arr[right].frequency < arr[smallest].frequency)
        smallest = right;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

// Function to build a min-heap
void buildMinHeap(struct SYMBOL arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);
}

// Function to extract the minimum element from the heap
struct SYMBOL extractMin(struct SYMBOL arr[], int* n) {
    struct SYMBOL min = arr[0];
    arr[0] = arr[*n - 1];
    (*n)--;
    minHeapify(arr, *n, 0);
    return min;
}

// Function to build the Huffman tree
struct Node* buildHuffmanTree(struct SYMBOL arr[], int n) {
    buildMinHeap(arr, n);
    while (n > 1) {
        struct SYMBOL left = extractMin(arr, &n);
        struct SYMBOL right = extractMin(arr, &n);
        struct SYMBOL combined;
        combined.frequency = left.frequency + right.frequency;
        struct Node* newNode = createNode(combined);
        newNode->left = createNode(left);
        newNode->right = createNode(right);
        arr[n++] = combined;
        buildMinHeap(arr, n);
    }
    return createNode(arr[0]);
}

// Function to perform in-order traversal of the Huffman tree
void inorderTraversal(struct Node* root) {
    if (root == NULL)
        return; 

    inorderTraversal(root->left);
    printf("%c ", root->symbol.alphabet);
    inorderTraversal(root->right);
}

int main() {
    int n;
    printf("Enter the number of distinct alphabets: ");
    scanf("%d", &n);

    struct SYMBOL symbols[n];

    printf("Enter the alphabets: ");
    for (int i = 0; i < n; i++) {
        scanf(" %c", &symbols[i].alphabet);
    }

    printf("Enter their frequencies: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &symbols[i].frequency);
    }

    struct Node* huffmanTree = buildHuffmanTree(symbols, n);

    printf("In-order traversal of the tree (Huffman): ");
    inorderTraversal(huffmanTree);

    return 0;
}
