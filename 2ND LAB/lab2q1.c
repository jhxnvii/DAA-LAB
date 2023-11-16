#include <stdio.h>
#include <stdlib.h>


void decimalToBinary(FILE *inputFile, FILE *outputFile, int n) {
    if (n == 0) {
        return;
    }

    int decimalNumber;
    if (fscanf(inputFile, "%d", &decimalNumber) != 1) {
        printf("Error reading decimal number from the input file.\n");
        exit(1);
    }

    int binary[64];
    int index = 0;
    while (decimalNumber > 0) {
        binary[index++] = decimalNumber % 2;
        decimalNumber /= 2;
    }

    
    for (int i = index - 1; i >= 0; i--) {
        fprintf(outputFile, "%d", binary[i]);
    }
    fprintf(outputFile, "\n");
    decimalToBinary(inputFile, outputFile, n - 1);
}

int main() {
    FILE *inputFile, *outputFile;
    int n;

    
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input.txt file.\n");
        return 1;
    }

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output.txt file.\n");
        fclose(inputFile);
        return 1;
    }

    // Input the value of 'n'
    printf("Enter the value of 'n': ");
    scanf("%d", &n);

    // Call the recursive function to convert decimals to binary and store in the output file
    decimalToBinary(inputFile, outputFile, n);

    // Close the file pointers
    fclose(inputFile);
    fclose(outputFile);

    printf("Conversion completed and stored in output.txt.\n");

    return 0;
}