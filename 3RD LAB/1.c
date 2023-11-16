#include <stdio.h>


int leftmostBinarySearch(int arr[], int size, int key, int *comparisons) {
    int low = 0;
    int high = size - 1;
    int result = -1;  

    while (low <= high) {
        int mid = low + (high - low) / 2; 

        (*comparisons)++;  // to keep track of how many comparisons made

        if (arr[mid] == key) {
            result = mid;  // Update result if key is found
            high = mid - 1;  // Move to the left subarray to find leftmost occurrence
        } else if (arr[mid] < key) {
            low = mid + 1;  // Move to the right subarray
        } else {
            high = mid - 1;  // Move to the left subarray
        }
    }

    return result;
}

int main() {
    int size;
    printf("Enter size of array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int key;
    printf("Enter the key to be searched: ");
    scanf("%d", &key);

    int comparisons = 0;  // Initialize the comparisons count
    int index = leftmostBinarySearch(arr, size, key, &comparisons);

    if (index != -1) {
        printf("%d found at index position %d\n", key, index);
        printf("Number of comparisons: %d\n", comparisons);
    } else {
        printf("%d not found in the array\n", key);
    }

    return 0;
}
