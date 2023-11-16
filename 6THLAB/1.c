#include <stdio.h>
#include <stdlib.h>

// Structure to represent an item
struct ITEM {
    int item_id;
    double item_profit;
    double item_weight;
    double profit_weight_ratio;
};

// Function to perform max-heapify
void maxHeapify(struct ITEM arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].profit_weight_ratio > arr[largest].profit_weight_ratio)
        largest = left;

    if (right < n && arr[right].profit_weight_ratio > arr[largest].profit_weight_ratio)
        largest = right;

    if (largest != i) {
        // Swap arr[i] and arr[largest]
        struct ITEM temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        maxHeapify(arr, n, largest);
    }
}

// Function to perform heap sort
void heapSort(struct ITEM arr[], int n) {
    // Build a max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);

    // Extract elements one by one from the heap
    for (int i = n - 1; i >= 0; i--) {
        // Move the current root to the end
        struct ITEM temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Call maxHeapify on the reduced heap
        maxHeapify(arr, i, 0);
    }
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    struct ITEM items[n];

    // Input items
    for (int i = 0; i < n; i++) {
        printf("Enter the profit and weight of item no %d: ", i + 1);
        scanf("%lf %lf", &items[i].item_profit, &items[i].item_weight);
        items[i].item_id = i + 1;
        items[i].profit_weight_ratio = items[i].item_profit / items[i].item_weight;
    }

    double capacity;
    printf("Enter the capacity of knapsack: ");
    scanf("%lf", &capacity);

    // Sort items by profit-weight ratio in non-increasing order
    heapSort(items, n);

    double maxProfit = 0.0;
    printf("Item No Profit Weight Amount to be taken\n");

    for (int i = 0; i < n; i++) {
        if (capacity <= 0)
            break;

        double fraction = 1.0;
        if (items[i].item_weight > 0)
            fraction = capacity / items[i].item_weight;

        double itemProfit = items[i].item_profit * fraction;
        printf("%d %.6lf %.6lf %.6lf\n", items[i].item_id, items[i].item_profit, items[i].item_weight, fraction);
        maxProfit += itemProfit;
        capacity -= (fraction * items[i].item_weight);
    }

    printf("Maximum profit: %.6lf\n", maxProfit);

    return 0;
}
