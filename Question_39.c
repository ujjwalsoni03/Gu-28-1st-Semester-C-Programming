#include <stdio.h> 
  
void manipulate_array(int arr[], int n) { 
    for (int i = 0; i < n - 1; i++) { 
        if (*(arr + i) % 2 == 0) { 
            *(arr + i) = *(arr + i) * *(arr + i + 1); 
        } else { 
            *(arr + i) = *(arr + i) / *(arr + i - 1); 
        } 
    } 
} 
  
int main() { 
    int n; 
    scanf("%d", &n); 
    int arr[n]; 
     
    for (int i = 0; i < n; i++) { 
        scanf("%d", &arr[i]); 
    } 
  
    manipulate_array(arr, n); 
  
    for (int i = 0; i < n; i++) { 
        printf("%d ", arr[i]); 
} 
printf("\n"); 
return 0; 
}