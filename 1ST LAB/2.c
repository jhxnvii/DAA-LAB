#include <stdio.h>

void findPrefixSum(int arr[], int n, int prefixSum[]) {
    prefixSum[0] = arr[0];

    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefixSum[n];
    findPrefixSum(arr, n, prefixSum);

    printf("Prefix Sum Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", prefixSum[i]);
    }
    printf("\n");

    return 0;
}
