#include <stdio.h>

#define MAX 100

// Define a structure for non-zero matrix elements
typedef struct {
    int row;
    int col;
    int value;
} SparseMatrixElement;

// Function to read a sparse matrix from input
void readMatrix(SparseMatrixElement matrix[], int *n) {
    scanf("%d", n); // Read number of non-zero elements
    for (int i = 0; i < *n; i++) {
        scanf("%d %d %d", &matrix[i].row, &matrix[i].col, &matrix[i].value);
    }
}

// Function to add two sparse matrices
int addMatrices(SparseMatrixElement matrix1[], int n1, SparseMatrixElement matrix2[], int n2, SparseMatrixElement result[]) {
    int i = 0, j = 0, k = 0;

    // Iterate through both matrices
    while (i < n1 && j < n2) {
        if (matrix1[i].row == matrix2[j].row && matrix1[i].col == matrix2[j].col) {
            // Add the values of the matching elements
            int sum = matrix1[i].value + matrix2[j].value;
            if (sum != 0) { // Only store non-zero results
                result[k].row = matrix1[i].row;
                result[k].col = matrix1[i].col;
                result[k].value = sum;
                k++;
            }
            i++;
            j++;
        } else if (matrix1[i].row < matrix2[j].row || (matrix1[i].row == matrix2[j].row && matrix1[i].col < matrix2[j].col)) {
            result[k++] = matrix1[i++];
        } else {
            result[k++] = matrix2[j++];
        }
    }

    // Add remaining elements from matrix1
    while (i < n1) {
        result[k++] = matrix1[i++];
    }

    // Add remaining elements from matrix2
    while (j < n2) {
        result[k++] = matrix2[j++];
    }

    return k; // Return the number of non-zero elements in the result
}

// Function to subtract two sparse matrices
int subtractMatrices(SparseMatrixElement matrix1[], int n1, SparseMatrixElement matrix2[], int n2, SparseMatrixElement result[]) {
    int i = 0, j = 0, k = 0;

    // Iterate through both matrices
    while (i < n1 && j < n2) {
        if (matrix1[i].row == matrix2[j].row && matrix1[i].col == matrix2[j].col) {
            // Subtract values when both matrices have the same element
            int diff = matrix1[i].value - matrix2[j].value;
            if (diff != 0) { // Only store non-zero results
                result[k].row = matrix1[i].row;
                result[k].col = matrix1[i].col;
                result[k].value = diff;
                k++;
            }
            i++;
            j++;
        } else if (matrix1[i].row < matrix2[j].row || (matrix1[i].row == matrix2[j].row && matrix1[i].col < matrix2[j].col)) {
            // If matrix1 has a smaller element, treat missing element in matrix 2 as 0
            result[k++] = matrix1[i++];
        } else {
            // If matrix2 has a smaller element, treat missing element in matrix 1 as 0 and subtract
            result[k].row = matrix2[j].row;
            result[k].col = matrix2[j].col;
            result[k].value = -matrix2[j].value; // Subtract element from matrix2 (i.e., treat matrix1 as 0)
            k++;
            j++;
        }
    }

    // Add remaining elements from matrix1
    while (i < n1) {
        result[k++] = matrix1[i++];
    }

    return k; // Return the number of non-zero elements in the result
}

// Function to print a sparse matrix
void printMatrix(SparseMatrixElement matrix[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d %d %d", matrix[i].row, matrix[i].col, matrix[i].value);
        if (i < n - 1) {
            printf("\n"); // Print newline for all but the last element
        }
    }
}

int main() {
    SparseMatrixElement matrix1[MAX], matrix2[MAX], result[MAX];
    int n1, n2, nResult;

    // Read the first matrix
    readMatrix(matrix1, &n1);

    // Read the second matrix
    readMatrix(matrix2, &n2);

    // Add the matrices
    nResult = addMatrices(matrix1, n1, matrix2, n2, result);

    // Print the addition result
    printf("Addition Result:\n");
    printMatrix(result, nResult);

    // Subtract the matrices
    nResult = subtractMatrices(matrix1, n1, matrix2, n2, result);

    // Print the subtraction result
    printf("\n\nSubtraction Result:\n");
    printMatrix(result, nResult);

    return 0;
}