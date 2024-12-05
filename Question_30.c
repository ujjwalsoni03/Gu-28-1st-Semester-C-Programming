#include <stdio.h>

#define MAX 100

// Function to get the input matrix
void getInputMatrix(int matrix[][MAX], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to find the maximum path sum
int findMaxPathSum(int matrix[][MAX], int n, int m) {
    int dp[MAX][MAX];

    // Initialize the dp table
    dp[0][0] = matrix[0][0];

    // Fill the first row (only can come from left)
    for (int j = 1; j < m; j++) {
        dp[0][j] = dp[0][j-1] + matrix[0][j];
    }

    // Fill the first column (only can come from above)
    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i-1][0] + matrix[i][0];
    }

    // Fill the rest of the dp table
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            dp[i][j] = matrix[i][j] + (dp[i-1][j] > dp[i][j-1] ? dp[i-1][j] : dp[i][j-1]);
        }
    }

    // Return the bottom-right corner value which contains the maximum path sum
    return dp[n-1][m-1];
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int matrix[MAX][MAX];
    
    // Get the input matrix
    getInputMatrix(matrix, n, m);

    // Find and print the maximum path sum
    printf("%d\n", findMaxPathSum(matrix, n, m));

    return 0;
}
