#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
    int id;
    char *name;
    int age;
    int height;
    int weight;
};

void swap(struct person *a, struct person *b) {
    struct person temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(struct person arr[], int n, int i) {
    int smallest = i;]
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].age < arr[smallest].age)
        smallest = left;

    if (right < n && arr[right].age < arr[smallest].age)
        smallest = right;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        minHeapify(arr, n, smallest);
    }
}

void maxHeapify(struct person arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].weight > arr[largest].weight)
        largest = left;

    if (right < n && arr[right].weight > arr[largest].weight)
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        maxHeapify(arr, n, largest);
    }
}

void buildMinHeap(struct person arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        minHeapify(arr, n, i);
}

void buildMaxHeap(struct person arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        maxHeapify(arr, n, i);
}

void printHeap(struct person arr[], int n) {
    printf("Id Name Age Height Weight(pound)\n");
    for (int i = 0; i < n; i++) {
        printf("%d %s %d %d %d\n",
               arr[i].id, arr[i].name, arr[i].age, arr[i].height, arr[i].weight);
    }
}

int main() {
    int n = 0;
    struct person *students = NULL;

    int option;
    do {
        printf("\nMAIN MENU (HEAP)\n");
        printf("1. Read Data\n");
        printf("2. Create and display a Min-heap based on the age\n");
        printf("3. Create and display a Max-heap based on the weight\n");
        printf("4. Display weight of the youngest person\n");
        printf("5. Insert a new person into the Min-heap\n");
        printf("6. Delete the oldest person\n");
        printf("7. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1: {
                printf("Enter the number of students: ");
                scanf("%d", &n);

                students = (struct person *)malloc(n * sizeof(struct person));

                printf("Enter student data (Id Name Age Height Weight(pound)):\n");
                for (int i = 0; i < n; i++) {
                    students[i].name = (char *)malloc(50 * sizeof(char));
                    scanf("%d %s %d %d %d",
                          &students[i].id, students[i].name,
                          &students[i].age, &students[i].height, &students[i].weight);
                }
                printf("Data read and stored.\n");
                break;
            }
            case 2:
                if (n > 0) {
                    buildMinHeap(students, n);
                    printf("Min-heap created based on age.\n");
                    printf("Min-Heap:\n");
                    printHeap(students, n);
                } else {
                    printf("No data available. Read data first.\n");
                }
                break;
            case 3:
                if (n > 0) {
                    buildMaxHeap(students, n);
                    printf("Max-heap created based on weight.\n");
                    printf("Max-Heap:\n");
                    printHeap(students, n);
                } else {
                    printf("No data available. Read data first.\n");
                }
                break;
            case 4:
                if (n > 0)
                    printf("Weight of the youngest student: %.2f kg\n", students[n-1].weight * 0.453592);
                else
                    printf("No data available.\n");
                break;
            case 5:
                // ... (insertion code)
                break;
            case 6:
                // ... (deletion code)
                break;
            case 7:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option.\n");
        }
    } while (option != 7);

    for (int i = 0; i < n; i++)
        free(students[i].name);
    free(students);

    return 0;
}
