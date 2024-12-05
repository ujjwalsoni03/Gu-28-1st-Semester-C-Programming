#include <stdio.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int n;
    
    // Input the size of the matrix
    scanf("%d", &n);
    
    // Declare the matrix
    int matrix[n][n];
    
    // Input the matrix values
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    // Variables to count mismatches for both patterns
    int flipsPattern1 = 0, flipsPattern2 = 0;
    
    // Traverse the matrix and compare with both patterns
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // For Pattern 1: (i + j) % 2 == 0 -> expected 1, else expected 0
            if (((i + j) % 2 == 0 && matrix[i][j] != 1) || ((i + j) % 2 != 0 && matrix[i][j] != 0)) {
                flipsPattern1++;
            }
            
            // For Pattern 2: (i + j) % 2 == 0 -> expected 0, else expected 1
            if (((i + j) % 2 == 0 && matrix[i][j] != 0) || ((i + j) % 2 != 0 && matrix[i][j] != 1)) {
                flipsPattern2++;
            }
        }
    }
    
    // Output the minimum flips required to match one of the patterns
    printf("%d\n", min(flipsPattern1, flipsPattern2));
    
    return 0;
}
