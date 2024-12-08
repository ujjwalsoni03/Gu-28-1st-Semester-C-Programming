#include <stdio.h> 
#include <stdlib.h> 
  
void rotateMatrix(int **matrix, int n) { 
    for (int i = 0; i < n; i++) { 
        for (int j = i; j < n; j++) { 
            int temp = matrix[i][j]; 
            matrix[i][j] = matrix[j][i]; 
            matrix[j][i] = temp; 
        } 
    } 
  
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n / 2; j++) { 
            int temp = matrix[i][j]; 
            matrix[i][j] = matrix[i][n - j - 1]; 
            matrix[i][n - j - 1] = temp; 
        } 
    } 
} 
  
int main() { 
    int n; 
    scanf("%d", &n); 
  
    int **matrix = (int **)malloc(n * sizeof(int *)); 
    for (int i = 0; i < n; i++) { 
        matrix[i] = (int *)malloc(n * sizeof(int)); 
    } 
  
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) { 
            scanf("%d", &matrix[i][j]); 
        } 
    } 
  
    rotateMatrix(matrix, n); 
  
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) { 
            printf("%d ", matrix[i][j]); 
        } 
        printf("\n"); 
    } 
  
    for (int i = 0; i < n; i++) { 
        free(matrix[i]); 
    } 
free(matrix); 
return 0; 
}