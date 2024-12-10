#include <stdio.h> 
#include <stdlib.h> 
  
void transposeMatrix(int **matrix, int m, int n) { 
    int **transposed = (int **)malloc(n * sizeof(int *)); 
    for (int i = 0; i < n; i++) { 
        transposed[i] = (int *)malloc(m * sizeof(int)); 
    } 
  
    for (int i = 0; i < m; i++) { 
        for (int j = 0; j < n; j++) { 
            transposed[j][i] = matrix[i][j]; 
        } 
    } 
  
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < m; j++) { 
            printf("%d ", transposed[i][j]); 
        } 
        printf("\n"); 
    } 
  
    for (int i = 0; i < n; i++) { 
        free(transposed[i]); 
    } 
    free(transposed); 
} 
  
int main() { 
    int m, n; 
    scanf("%d %d", &m, &n); 
  
    int **matrix = (int **)malloc(m * sizeof(int *)); 
    for (int i = 0; i < m; i++) { 
        matrix[i] = (int *)malloc(n * sizeof(int)); 
    } 
  
    for (int i = 0; i < m; i++) { 
        for (int j = 0; j < n; j++) { 
            matrix[i][j] = i * j; 
        } 
    } 
  
    transposeMatrix(matrix, m, n); 
  
    for (int i = 0; i < m; i++) { 
        free(matrix[i]); 
    } 
    free(matrix); 
  
    return 0; 
} 