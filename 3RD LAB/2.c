#include <stdio.h>

int insertionSort(int arr[], int size) {
    int comparisons = 0;
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            comparisons++;
        }
        
        arr[j + 1] = key;
    }
    return comparisons;
}

int readFromFile(const char *fileName, int arr[]) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", fileName);
        return 0;
    }

    int size = 0;
    while (fscanf(file, "%d", &arr[size]) != EOF) {
        size++;
    }

    fclose(file);
    return size;
}


void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int option;
    int arr[500]; // Assuming a maximum of 500 elements

    printf("MAIN MENU (INSERTION SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. EXIT\n");
    printf("Enter option: ");
    scanf("%d", &option);

    int size = 0;
    const char *inputFileName = NULL;
    const char *outputFileName = NULL;

    switch (option) {
        case 1:
            inputFileName = "inAsce.dat";
            outputFileName = "outInsAsce.dat";
            break;
        case 2:
            inputFileName = "inDesc.dat";
            outputFileName = "outInsDesc.dat";
            break;
        case 3:
            inputFileName = "inRand.dat";
            outputFileName = "outInsRand.dat";
            break;
        case 4:
            printf("Exiting program.\n");
            return 0;
        default:
            printf("Invalid option.\n");
            return 1;
    }

    size = readFromFile(inputFileName, arr);
    if (size == 0) {
        return 1;
    }

    printf("Before Sorting: ");
    displayArray(arr, size);

    int comparisons = insertionSort(arr, size);

    printf("After Sorting: ");
    displayArray(arr, size);

    printf("Number of Comparisons: %d\n", comparisons);

    // Determine scenario based on the number of comparisons
    if (comparisons == (size - 1)) {
        printf("Scenario: Best-case\n");
    } else if (comparisons == (size * (size - 1) / 2)) {
        printf("Scenario: Worst-case\n");
    } else {
        printf("Scenario: Neither best nor worst-case\n");
    }

    // Write sorted data to the output file
    FILE *outputFile = fopen(outputFileName, "w");
    for (int i = 0; i < size; i++) {
        fprintf(outputFile, "%d ", arr[i]);
    }
    fclose(outputFile);

    return 0;
}
