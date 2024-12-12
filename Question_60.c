#include <stdio.h>

// Define a structure to hold the results
typedef struct {
    int sum;
    long long product; // Use long long to handle large products
    int countGreaterThanThreshold;
} Result;

// Recursive function to traverse the 2D array
Result computeArrayProperties(int **array, int rows, int cols, int row, int col, int threshold) {
    Result result = {0, 1, 0}; // Initialize sum to 0, product to 1, count to 0

    // Base case: if the row index exceeds the number of rows, return the result
    if (row >= rows) {
        return result;
    }

    // Base case: if the column index exceeds the number of columns, move to the next row
    if (col >= cols) {
        return computeArrayProperties(array, rows, cols, row + 1, 0, threshold);
    }

    // Process the current element
    result.sum += array[row][col];
    result.product *= array[row][col];

    if (array[row][col] > threshold) {
        result.countGreaterThanThreshold++;
    }

    // Recursive call for the next column
    Result nextResult = computeArrayProperties(array, rows, cols, row, col + 1, threshold);

    // Combine results
    result.sum += nextResult.sum;
    result.product *= nextResult.product; // Combine product
    result.countGreaterThanThreshold += nextResult.countGreaterThanThreshold;

    return result;
}

int main() {
    int rows, cols;

    // Read the dimensions of the 2D array
    //printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    // Dynamically allocate memory for the 2D array
    int **array = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        array[i] = (int *)malloc(cols * sizeof(int));
    }

    // Read the elements of the 2D array
    //printf("Enter the elements of the 2D array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &array[i][j]);
        }
    }

    // Read the threshold
    int threshold;
    //printf("Enter the threshold: ");
    scanf("%d", &threshold);

    // Call the recursive function
    Result result = computeArrayProperties(array, rows, cols, 0, 0, threshold);

    // Print the results
    printf("Sum: %d\n", result.sum);
    printf("Product: %lld\n", result.product);
    printf("Count greater than %d: %d\n", threshold, result.countGreaterThanThreshold);

    // Free allocated memory
    for (int i = 0; i < rows; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}