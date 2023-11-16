#include <stdio.h>
#include <stdlib.h>
#include<limits.h>

void findSecondSmallestAndLargest(int arr[], int n) {
    int smallest = INT_MAX;
    int secondSmallest = INT_MAX;
    int largest = INT_MIN;
    int secondLargest = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (arr[i] < smallest) {
            secondSmallest = smallest;
            smallest = arr[i];
        } else if (arr[i] < secondSmallest && arr[i] != smallest) {
            secondSmallest = arr[i];
        }

        if (arr[i] > largest) {
            secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != largest) {
            secondLargest = arr[i];
        }
    }

    printf("Second Smallest: %d\n", secondSmallest);
    printf("Second Largest: %d\n", secondLargest);
}

int main() {
    int n;
    FILE *file;
    char filename[100];

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the filename to read the elements from: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        free(arr);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        if (fscanf(file, "%d", &arr[i]) != 1) {
            printf("Error reading from file.\n");
            free(arr);
            fclose(file);
            return 1;
        }
    }

    fclose(file);

    findSecondSmallestAndLargest(arr, n);

    free(arr);

    return 0;
}
