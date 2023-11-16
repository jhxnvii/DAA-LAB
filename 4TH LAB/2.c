#include <stdio.h>
#include <stdlib.h>

int comparisons = 0;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
            comparisons++;
        }
    }

    swap(&arr[i + 1], &arr[high]);
    comparisons++;
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void sortAndDisplay(int input[], int size, const char *outputFileName) {
    FILE *outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }

    quickSort(input, 0, size - 1);
    
    printf("After Sorting: ");
    displayArray(input, size);
    printf("Number of Comparisons: %d\n", comparisons);
    if (comparisons == (size - 1)) {
        printf("Scenario: Best-case\n");
    } else if (comparisons == ((size * (size - 1)) / 2)) {
        printf("Scenario: Worst-case\n");
    }

    for (int i = 0; i < size; i++) {
        fprintf(outputFile, "%d ", input[i]);
    }

    fclose(outputFile);
}

int main() {
    int option;
    int size = 0;
    int input[500];

    printf("MAIN MENU (QUICK SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. EXIT\n");

    printf("Enter option: ");
    scanf("%d", &option);

    if (option == 1) {
        FILE *file = fopen("inAsce.dat", "r");
        while (fscanf(file, "%d", &input[size]) == 1) {
            size++;
        }
        fclose(file);
        printf("Before Sorting: ");
        displayArray(input, size);
        sortAndDisplay(input, size, "outQuickAsce.dat");
    } else if (option == 2) {
        FILE *file = fopen("inDesc.dat", "r");
        while (fscanf(file, "%d", &input[size]) == 1) {
            size++;
        }
        fclose(file);
        printf("Before Sorting: ");
        displayArray(input, size);
        sortAndDisplay(input, size, "outQuickDesc.dat");
    } else if (option == 3) {
        FILE *file = fopen("inRand.dat", "r");
        while (fscanf(file, "%d", &input[size]) == 1) {
            size++;
        }
        fclose(file);
        printf("Before Sorting: ");
        displayArray(input, size);
        sortAndDisplay(input, size, "outQuickRand.dat");
    } else if (option == 4) {
        printf("Exiting the program.\n");
    } else {
        printf("Invalid option.\n");
    }

    return 0;
}
