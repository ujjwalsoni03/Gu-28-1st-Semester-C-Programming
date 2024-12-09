#include <stdio.h> 
#include <stdlib.h> 
  
int main() { 
    int n; 
    scanf("%d", &n); 
  
    int *original = (int *)malloc(n * sizeof(int)); 
    if (original == NULL) { 
        printf("Memory allocation failed\n"); 
        return 1; 
    } 
  
    for (int i = 0; i < n; i++) { 
        scanf("%d", &original[i]); 
    } 
  
    int *copied = (int *)malloc(2 * n * sizeof(int)); 
    if (copied == NULL) { 
        printf("Memory allocation failed\n"); 
        free(original); 
        return 1; 
    } 
  
    for (int i = 0; i < n; i++) { 
        copied[i] = original[i]; 
    } 
  
    for (int i = n; i < 2 * n; i++) { 
        copied[i] = 0; 
    } 
  
    printf("Original array: "); 
    for (int i = 0; i < n; i++) { 
        printf("%d ", original[i]); 
    } 
    printf("\n"); 
  
    printf("Copied array: "); 
    for (int i = 0; i < 2 * n; i++) { 
        printf("%d ", copied[i]); 
    } 
    printf("\n"); 
  
    free(original); 
    free(copied); 
  
    return 0; 
} 
