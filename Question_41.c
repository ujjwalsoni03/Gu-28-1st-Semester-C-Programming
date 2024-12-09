#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
  
void reverseString(char *str) { 
    int start = 0, end = strlen(str) - 1; 
    while (start < end) { 
        char temp = str[start]; 
        str[start] = str[end]; 
        str[end] = temp; 
        start++; 
        end--; 
    } 
} 
  
int main() { 
    int n; 
    scanf("%d", &n); 
  
    char **arr = (char **)malloc(n * sizeof(char *)); 
    for (int i = 0; i < n; i++) { 
        arr[i] = (char *)malloc(100 * sizeof(char)); 
        scanf("%s", arr[i]); 
    } 
  
    for (int i = 0; i < n; i++) { 
        reverseString(arr[i]); 
    } 
  
    char *temp = arr[0]; 
    arr[0] = arr[n - 1]; 
    arr[n - 1] = temp; 
  
    for (int i = 0; i < n; i++) { 
        printf("%s\n", arr[i]); 
    } 
  
    for (int i = 0; i < n; i++) { 
        free(arr[i]); 
    } 
    free(arr); 
  
    return 0; 
}