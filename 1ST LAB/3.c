#include <stdio.h>

int countDuplicates(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        int isDuplicate = 0;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = 1;
                break;
            }
        }
        if (isDuplicate) {
            count++;
        }
    }
    return count;
}

int findMostRepeatingElement(int arr[], int n) {
    int maxCount = 0;
    int mostRepeatingElement = arr[0];

    for (int i = 0; i < n; i++) {
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }

        if (count > maxCount) {
            maxCount = count;
            mostRepeatingElement = arr[i];
        }
    }

    return mostRepeatingElement;
}

int main() {
    int n;
    FILE *file;
    char filename[100];

    printf("Enter how many numbers you want to read from file: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the filename to read the numbers from: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        if (fscanf(file, "%d", &arr[i]) != 1) {
            printf("Error reading from file.\n");
            fclose(file);
            return 1;
        }
    }

    fclose(file);

    printf("The content of the array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int totalDuplicates = countDuplicates(arr, n);
    printf("Total number of duplicate values = %d\n", totalDuplicates);

    int mostRepeatingElement = findMostRepeatingElement(arr, n);
    printf("The most repeating element in the array = %d\n", mostRepeatingElement);

    return 0;
}
