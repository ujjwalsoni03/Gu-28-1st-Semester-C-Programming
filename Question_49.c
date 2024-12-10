#include <stdio.h> 
#include <stdlib.h> 
  
void multiplyMatrices(int **matrix1, int **matrix2, int **result, int R1, int C1, int R2, int C2) { 
    for (int i = 0; i < R1; i++) { 
        for (int j = 0; j < C2; j++) { 
            result[i][j] = 0; 
            for (int k = 0; k < C1; k++) { 
                result[i][j] += matrix1[i][k] * matrix2[k][j]; 
            } 
        } 
    } 
} 
  
int main() { 
    int R1, C1, R2, C2; 
    scanf("%d %d", &R1, &C1); 
    scanf("%d %d", &R2, &C2); 
  
    if (C1 != R2) { 
        printf("Matrix multiplication is not possible due to incompatible dimensions.\n"); 
        return 1; 
    } 
  
    int **matrix1 = (int **)malloc(R1 * sizeof(int *)); 
    for (int i = 0; i < R1; i++) { 
        matrix1[i] = (int *)malloc(C1 * sizeof(int)); 
    } 
  
    int **matrix2 = (int **)malloc(R2 * sizeof(int *)); 
    for (int i = 0; i < R2; i++) { 
        matrix2[i] = (int *)malloc(C2 * sizeof(int)); 
    } 
  
    int **result = (int **)malloc(R1 * sizeof(int *)); 
    for (int i = 0; i < R1; i++) { 
        result[i] = (int *)malloc(C2 * sizeof(int)); 
    } 
  
    for (int i = 0; i < R1; i++) { 
        for (int j = 0; j < C1; j++) { 
            scanf("%d", &matrix1[i][j]); 
        } 
    } 
  
    for (int i = 0; i < R2; i++) { 
        for (int j = 0; j < C2; j++) { 
            scanf("%d", &matrix2[i][j]); 
        } 
    } 
  
    multiplyMatrices(matrix1, matrix2, result, R1, C1, R2, C2); 
  
    for (int i = 0; i < R1; i++) { 
        for (int j = 0; j < C2; j++) { 
            printf("%d ", result[i][j]); 
        } 
        printf("\n"); 
    } 
  
    for (int i = 0; i < R1; i++) { 
        free(matrix1[i]); 
    } 
    free(matrix1); 
  
    for (int i = 0; i < R2; i++) { 
        free(matrix2[i]); 
    } 
    free(matrix2); 
  
    for (int i = 0; i < R1; i++) { 
        free(result[i]); 
    } 
    free(result); 
  
    return 0; 
}