#include <stdio.h> 
#include <stdlib.h> 
  
void modifyArray(int *arr, int n) { 
    for (int i = 0; i < n - 1; i++) { 
        arr[i] += arr[i + 1]; 
    } 
     
    int temp = arr[0]; 
    arr[0] = arr[n - 1]; 
    arr[n - 1] = temp; 
} 
  
int main() { 
    int n; 
    scanf("%d", &n); 
    int *arr = (int *)malloc(n * sizeof(int)); 
     
    for (int i = 0; i < n; i++) { 
        arr[i] = i * i; 
    } 
  
    modifyArray(arr, n); 
  
for (int i = 0; i < n; i++) { 
printf("%d ", arr[i]); 
} 
printf("\n"); 
free(arr); 
return 0; 
}