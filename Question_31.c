#include <stdio.h> 
  
void reverse(int arr[], int start, int end) { 
    while (start < end) { 
        int temp = arr[start]; 
        arr[start] = arr[end]; 
        arr[end] = temp; 
        start++; 
        end--; 
    } 
} 
  
void rotateArray(int arr[], int n, int d, char dir) { 
    if (dir == 'L') { 
        d = d % n; 
        reverse(arr, 0, n - 1); 
        reverse(arr, 0, n - d - 1); 
        reverse(arr, n - d, n - 1); 
    } else if (dir == 'R') { 
        d = d % n; 
        d = n - d; 
        reverse(arr, 0, n - 1); 
        reverse(arr, 0, n - d - 1); 
        reverse(arr, n - d, n - 1); 
    } 
} 
  
int main() { 
    int n, d; 
    char dir; 
     
    scanf("%d %d", &n, &d); 
     
    int arr[n]; 
    for (int i = 0; i < n; i++) { 
        scanf("%d", &arr[i]); 
    } 
     
    scanf(" %c", &dir); 
  
    rotateArray(arr, n, d, dir); 
     
    for (int i = 0; i < n; i++) { 
        printf("%d ", arr[i]); 
    } 
    printf("\n"); 
     
return 0;
}