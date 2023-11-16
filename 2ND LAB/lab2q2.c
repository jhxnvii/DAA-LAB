#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

void findGCDs(FILE *input, FILE *output) {
    int a, b;
    while (fscanf(input, "%d %d", &a, &b) == 2) {
        int result = gcd(a, b);
        fprintf(output, "The GCD of %d and %d is %d\n", a, b, result);
    }
}

int main() {
    // Hard-code the input and output file names
    char *inputFileName = "inGcd.dat";
    char *outputFileName = "outGcd.dat";

    FILE *inputFile = fopen(inputFileName, "r");
    FILE *outputFile = fopen(outputFileName, "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    findGCDs(inputFile, outputFile);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}
